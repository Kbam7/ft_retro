#include "Bullet.hpp"

/////////////////////////////////[  constructor/destructor  ]////////////////////////////////////////

Bullet::Bullet(void) : this->_character = '-';
{
    shoot(*this);
}

Bullet::Bullet(Bullet const & src)
{
    *this = src;
    return;
}


Bullet::~Bullet(void)
{
    return;
}


/////////////////////////////////[  overloaded operators  ]////////////////////////////////////////

Bullet& Bullet::operator=(Bullet const & rhs)
{
    if (this != &rhs)
    {
		this->_xLoc = rhs._xLoc;
		this->_yLoc = rhs._yLoc;
        this->_character = rhs._character;
    }
    return *this;
}

/////////////////////////////////[  member functions  ]////////////////////////////////////////

void    Bullet::shoot(object)
{

    int *pLoc = getplayerLocation();                                 // we need the player location function
    setLocation(pLoc[0], pLoc[1])
    if ((hitobject() != 1))                                      //get x max for bullet end
    {
        setLocation(pLoc[0] += 1, pLoc[1])
    }
}



/*         ----- if we have a boss that can shoot back

bool           Bullet::hitPlayer();
{
    int *pLoc = getplayerlocation();                               // get the proper location
    if (((this->xLoc == pLoc[0]) && (this->yloc == pLoc[1]))       // check for unit collision
    {
        delete this;
        return true;
    }
    return false;
}
*/

bool        Bullet::hitBullet();
{
    int *pLoc = getlocation();
    if (((this->xLoc == pLoc[0]) && (this->yloc == pLoc[1]))       // check for bullet collision
    {
        return true;
    }
    return false;
}