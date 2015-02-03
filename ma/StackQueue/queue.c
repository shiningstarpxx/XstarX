/*
 * ====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:45:42
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#include "queue.h"

int queue_enqueue( Queue *queue, const void *data )
{
	return list_ins_next(queue, list_tail(queue), data);
}

int queue_dequeue( Queue *queue, void **data )
{
	return list_rem_next(queue, NULL, data );
}
