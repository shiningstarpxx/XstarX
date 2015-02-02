#ifndef SOCKET_COMMON_H
#define SOCKET_COMMON_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <string>

using namespace std;
#define EPOLL_NUM 65536
#define WORK_THREAD_NUM 2
#define EPOLL_MAX_NUM 1024

#define LISTEN_PORT 8001
#define LISTEN_MAX_NUM 4096

#define MAX_NET_DATA 4096

#define TCP_PROTOCOL 1

struct epdata
{
	int fd;
	int thread_index;
	bool user;
	char send_data[MAX_NET_DATA];
	int send_len;
	char recv_data[MAX_NET_DATA];
	int recv_len;
	int data_pos;
	epdata()
	{
		fd = -1;
		thread_index = -1;
		user = false;
		send_len = 0;
		recv_len = 0;
		data_pos = 0;
	}
	void clear()
	{
		fd = -1;
		thread_index = -1;
		user = false;
		send_len = 0;
		recv_len = 0;
		data_pos = 0;
		memset(recv_data,0,MAX_NET_DATA);
		memset(send_data,0,MAX_NET_DATA);
	}
};

bool g_server_flag = false;
epdata g_ed[EPOLL_NUM];
int g_epfd[WORK_THREAD_NUM];
int g_lisfd;

int g_index = 0;

#endif
