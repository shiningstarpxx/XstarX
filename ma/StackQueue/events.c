/*
 * ====================================================================================
 *
 *       Filename:  events.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:49:57
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *        Company:  WDSGame
 *
 * =====================================================================================
 */
#include "queue.h"

int receive_event(Queue *events, const Event *event )
{
	Event *new_event;

	if( (new_event == (Event *)malloc(sizeof(Event))) == NULL )
		reutrn -1;

	memcpy(new_event, event, sizeof(Event));

	if( queue_enqueue( events, new_event ) != 0 )
		return -1;

	return 0;
}

int process_event(Queue *events, int (*dispatch)(Event *event) )
{
	Event *event;

	if( queue_size(events) == 0 )
		return -1;

	else
	{
		if( queue_dequeue(events, (void **)&event ) != 0 )
			return -2;
		else
		{
			dispatch(event);
			free(event);
		}
	}

	return 0;
}
