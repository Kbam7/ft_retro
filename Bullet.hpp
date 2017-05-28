
#ifndef _BULLET_HPP_
#define _BULLET_HPP_

#include "GameObject.hpp"                   			  // soon to be base

#include <ctime>

class Bullet : Public Base
{
	public:
		Bullet(void);
		Bullet(Bullet const & src);
		Bullet& operator=(Bullet const & rhs);
		~Bullet(void);

int			*getlocation();
void		setlocation(int x, int y);


void	    displayBullet();
void    	shoot(Bullet object);                         // fly accross the screen
void        hitPlayer();
void        hitBullet();


		

	private:

		int		_xLoc;
		int		_yLoc;
        char	_character;
		int		*location;


};

#endif