/*
 * =====================================================================================
 *
 *       Filename:  directls.h
 *
 *    Description:  direct list
 *
 *        Version:  1.0
 *        Created:  10/06/2014 15:12:52
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#ifndef DRIECTLS_H
#define DRIECTLS_H

#include <dirent.h>

typedef struct Directory_
{
	char 	name[MAXNAMLEN + 1]; 
} Directory;

int directory(const char *path, Directory **dir );

#endif
