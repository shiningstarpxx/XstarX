/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:  some common sort methods 
 *
 *        Version:  1.0
 *        Created:  10/06/2014 12:53:00
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *        Company:  WDSGame
 *
 * =====================================================================================
 */

#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <string.h>

/* @param: esize, element size */
int issort( void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

int qksort( void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));
#endif
