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
 *        Company:  WDSGame
 *
 * =====================================================================================
 */
#ifndef OBSERVER_PATTERN_OBJECT
#define OBSERVER_PATTERN_OBJECT

#include <vector>
#include "ObserverPattern_observer.h"

using namespace std;


class EventManager
{
	vector<Observer> observers_;
	vector<int> data_;
	bool changed_;

public:
	
	EventManager()
	{
		changed_ = false;
	}

	void add_observer( Observer o )
	{
		observers_.push_back( o );
	}

	void remove_observer( Observer o )
	{
	}

	void notify_observer()
	{
		if( changed_ )
		{
			for( int i=0; i<observers_.size(); i++ )
			{
				observers_[i].update( data_ );	
			}

			changed_ = false;
		}
	}
};

#endif
