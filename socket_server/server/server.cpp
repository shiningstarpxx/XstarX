#include"server.h"

int main()
{
	if(init_server(TCP_PROTOCOL) < 0) return -1;
	
	pthread_t listen_pt;
	pthread_create(&listen_pt,NULL,listen_thread,NULL);
	pthread_t work_pt[WORK_THREAD_NUM];
	for(int i = 0;i < WORK_THREAD_NUM;i++)
	{
		pthread_create(&work_pt[i],NULL,work_thread,&g_epfd[i]);
	}

	for( int i = 0; i < WORK_THREAD_NUM; ++i )
	{
		pthread_join( work_pt[i], NULL );
	}
	pthread_join(listen_pt,NULL);
	
	return 0;
}
