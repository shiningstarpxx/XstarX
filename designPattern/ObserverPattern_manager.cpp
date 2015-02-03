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
#include <vector>
#include "ObserverPattern_manager.h"

using namespace std;

int main()
{
	EventManager manager;

	Lobby lobby ;
	Battle battle;

	manager.add_observer( lobby );
	manager.add_observer( battle );
	return 0;
}
