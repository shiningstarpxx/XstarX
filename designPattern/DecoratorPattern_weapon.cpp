/*
 * ====================================================================================
 *
 *       Filename:  DecoratorPattern_weapon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2015 19:33:17
 *       Revision:  $Id$ 
 *       Compiler:  gcc
 *
 *         Author:  michaelpei (XingxinPei), xingxinpei@gmai.com, xingxinpei@icloud.com
 *
 * =====================================================================================
 */
#include <stdio.h>


class AbstractWeapon
{
public:
	virtual int get_damage() { return 0;} 
};

class Sword : public AbstractWeapon
{
	int damage_;

public:
	
	Sword( int v )
	{
		damage_ = v;
	}
	
	int get_damage()
	{
		return damage_;
	}
};

class Stone : public AbstractWeapon
{
};

class Ruby : public Stone
{
	AbstractWeapon *weapon_;
public:

	Ruby(AbstractWeapon *weapon )
	{
		weapon_ = weapon;
	}

	int get_damage()
	{
		return weapon_->get_damage() + 10;
	}
};

int main()
{
	AbstractWeapon *s = new Sword(100);
	s = new Ruby( s );

	printf("the damage is now %d\n", s->get_damage() );
	return 0;
}

