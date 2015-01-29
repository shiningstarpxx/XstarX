/*
 * ====================================================================================
 *
 *       Filename:  game.cpp
 *
 *    Description:  strategy example
 *
 *        Version:  1.0
 *        Created:  01/04/2015 18:59:32
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *        Company:  WDSGame
 *
 * =====================================================================================
 */
class Strategy
{
public:
	void select( int a, int b, int c )
	{}
};

class AttackStrategy : public Strategy
{
public:
	void select( int a, int b, int c ){}
};

class DefenseStrategy : public Strategy
{
public:
	void select( int a, int b, int c ){}
};

class BalanceStrategy : public Strategy
{
public:
	void select( int a, int b, int c ){}
};


class Game
{
private:
	Strategy strategy_;

public:
	void set_strategy( Strategy s )
	{
		strategy_ = s;
	}

	void run()
	{
		int paramA, paramB, paramC;

		strategy_.select( paramA, paramB, paramC );
	}
};
int main()
{
	Game game;

	Strategy *s;

	int index = 1;

	if( index == 1 ) s = new AttackStrategy();
	else if( index == 2 ) s = new DefenseStrategy();
	else if( index == 3 ) s = new BalanceStrategy();

	game.set_strategy( *s );
	game.run();

	delete s;

	return 0;
}
