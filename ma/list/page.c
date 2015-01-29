/*
 * ====================================================================================
 *
 *       Filename:  page.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2014 15:27:27
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *        Company:  WDSGame
 *
 * =====================================================================================
 */
#include "page.h"

int replace_page( CListElmt **current)
{
	while(((Page *)(*current)->data)->reference != 0 )
	{
		((Page *)(*current)->data)->reference = 0;
		*current = clist_next(*current);
	}
	return ((Page *)(*current)->data)->number;
}
