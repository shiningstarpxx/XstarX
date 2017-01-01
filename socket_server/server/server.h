#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include "common.h"

void handle_signal(int no)
{
	cout << "handle signal, no is " << no << endl;
	g_server_flag = true;
}

void clean_connection(int fd)
{
	struct epoll_event ev;
	int work_index = g_ed[fd].thread_index;
	g_ed[fd].clear();
	epoll_ctl(g_epfd[work_index],EPOLL_CTL_DEL,fd,&ev);
	close(fd);
}

int create_listen(int protocol)
{
	if(protocol == TCP_PROTOCOL)
	{
		g_lisfd = socket(AF_INET, SOCK_STREAM, 0);

		int reuse = 1;
		setsockopt(g_lisfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
		int flag;
		flag = fcntl(g_lisfd, F_GETFL );
		fcntl(g_lisfd, F_SETFL, flag | O_NONBLOCK );

		struct sockaddr_in lis_addr;
		lis_addr.sin_family = AF_INET;
		lis_addr.sin_port = htons(LISTEN_PORT);
		lis_addr.sin_addr.s_addr = htons(INADDR_ANY);
		if(bind(g_lisfd, (struct sockaddr *)&lis_addr, sizeof( lis_addr)) == -1)
		{
			cout << "bind error" << endl;
			return -1;
		}

		if(listen(g_lisfd, LISTEN_MAX_NUM))
		{
			cout << "listen error" << endl;
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

int init_server(int protocol)
{
	struct sigaction act;
	memset(&act, 0, sizeof(act));

	act.sa_handler = handle_signal;
	sigaction( SIGINT, &act, NULL );
	sigaction( SIGTERM, &act, NULL );

	sigset_t signal_mask;
	sigemptyset(&signal_mask);
	sigaddset(&signal_mask, SIGPIPE);
	pthread_sigmask(SIG_BLOCK, &signal_mask, NULL);

	for(int i = 0;i < WORK_THREAD_NUM;i++)
	{
		g_epfd[i] = epoll_create(EPOLL_MAX_NUM);
	}

	if(create_listen(protocol) < 0)
	{
		cout << "init server error" << endl;
		return -1;
	}
	
	cout << "init server success" << endl;
	return 0;
}

void handle_accept()
{
	for(int num = 0;num < LISTEN_MAX_NUM;num++)
	{
		int sock_fd = accept(g_lisfd,NULL,NULL);
		if(sock_fd < 0)
		{
			if(errno == EINTR)
			{
				cout << "client connect error" << endl;
				continue;
			}
			if(errno == EAGAIN)
			{
				cout << "accept connect complete" << endl;
				break;
			}
		}
		else
		{
			cout << "client connecting" << endl;
			int flag;
			flag = fcntl(sock_fd,F_GETFL);
			fcntl(sock_fd,F_SETFL,flag|O_NONBLOCK);

			g_ed[sock_fd].fd = sock_fd;
			g_ed[sock_fd].thread_index = g_index%WORK_THREAD_NUM;
			g_ed[sock_fd].user = true;

			struct epoll_event e;
			e.events = EPOLLIN;
			e.data.fd = sock_fd;
			epoll_ctl(g_epfd[g_index%WORK_THREAD_NUM],EPOLL_CTL_ADD,sock_fd,&e);
			g_index++;
		}
	}
}
void *listen_thread(void *arg)
{
	int lis_epfd = epoll_create(1);
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = g_lisfd;
	epoll_ctl(lis_epfd,EPOLL_CTL_ADD,g_lisfd,&ev);

	struct epoll_event lis_ev;
	while(!g_server_flag)
	{
		int ev_num = epoll_wait(lis_epfd,&lis_ev,1,1000);
		if(ev_num > 0)
		{
			handle_accept();
		}
	}
}

int handle_recv(int fd)
{
	int len = recv(fd,g_ed[fd].recv_data+g_ed[fd].recv_len,MAX_NET_DATA-g_ed[fd].recv_len,0);
	g_ed[fd].recv_len += len;
	if(len < 0)
	{
		if(errno != EAGAIN && errno != EINTR && errno != EINPROGRESS)
		{
			cout << "recv error" << endl;
			return -1;
		}
		else
		{
			return 0;
		}
	}
	else if(len == 0)
	{
		cout << "client close connection" << endl;
		return -1;
	}
	else
	{
		
	}
}

int handle_send(int fd)
{
	int len = send(fd,g_ed[fd].send_data+g_ed[fd].data_pos,g_ed[fd].send_len,0);
	if(len < 0)
	{
		if(errno != EAGAIN && errno != EINTR && errno != EINPROGRESS)
		{
			cout << "send error" << endl;
			return -1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		g_ed[fd].data_pos += len;
		g_ed[fd].send_len -= len;
		return 0;
	}
}

void *work_thread(void *arg)
{
	int work_epfd = *(int*)arg;
	struct epoll_event ev;
	while(!g_server_flag)
	{
		int ev_num = epoll_wait(work_epfd,&ev,1,1000);		//每次处理一件事
		if(ev_num > 0)
		{
			if(ev.events & EPOLLIN)
			{
				if(handle_recv(ev.data.fd) < 0)	clean_connection(ev.data.fd);
			}
			if(ev.events & EPOLLOUT)
			{
				if(handle_send(ev.data.fd) < 0)	clean_connection(ev.data.fd);
				if(g_ed[ev.data.fd].send_len <= 0)
				{
					ev.events = EPOLLIN;
					epoll_ctl(work_epfd,EPOLL_CTL_MOD,ev.data.fd,&ev);
				}
			}
			if(g_ed[ev.data.fd].send_len > 0)
			{
				ev.events |= EPOLLOUT;
				epoll_ctl(work_epfd,EPOLL_CTL_MOD,ev.data.fd,&ev);
			}
		}
	}
}

#endif
