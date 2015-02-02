/*
 * ====================================================================================
 *
 *       Filename:  ObserverPattern_manager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2015 16:18:49
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#ifndef OBSERVER_PATTERN_OBSERVER
#define OBSERVER_PATTERN_OBSERVER

#include <vector>
#include "ObserverPattern_manager.h"

using namespace std;

class Observer
{
	
public:
	
	void update( vector<int> data )
	{
		
	}
};


class Lobby : public Observer
{
public:

	void update( vector<int> data )
	{

	}
};

class Battle : public Observer
{
public:

	void update( vector<int> data )
	{

	}
};

#endif
