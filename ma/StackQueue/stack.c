/*
 * ====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:39:46
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#include "stack.h"

int stack_push( Stack *stack, const void *data )
{
	return list_ins_next(stack, NULL, data );
}

int stack_pop( Stack *stack, void **data )
{
	return list_rem_next(stack, NULL, data );
}
