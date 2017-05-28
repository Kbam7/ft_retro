
#ifndef _Entity_HPP_
#define _Entity_HPP_

#include "GameObject.hpp"


class Entity : public GameObject
{
	public:

Entity(void);
Entity(int num);
Entity(Entity const & src);
Entity& operator=(Entity const & rhs);
~Entity(void);


void    		shoot(Entity object, int location);          
bool         	hitPlayer();
bool         	hitBullet();

// have collision detection -- 

private:

int		_xmax;
int		_xLoc;
int		_yLoc;
Entity  *_object;
int     _amount;
char	_character;
int		*location;
};

#endif
