/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  stack 
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:35:49
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *        Company:  WDSGame
 *
 * =====================================================================================
 */
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "../list/list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data )
#define stack_size list_size

#endif
