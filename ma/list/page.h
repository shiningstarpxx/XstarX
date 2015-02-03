/*
 * =====================================================================================
 *
 *       Filename:  page.h
 *
 *    Description:  list example
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:25:57
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#ifndef PAGE_H
#define PAGE_H

#include "clist.h"

typedef struct Page_
{
	int number;
	int reference;
} Page;

int replace_page(CListElmt **current);

#endif
