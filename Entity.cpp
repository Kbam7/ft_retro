#include "Entity.hpp"


/////////////////////////////////[  constructor/destructor  ]////////////////////////////////////////

Entity::Entity(void) : this->_character = '8'
{
    shoot(*this);

}

Entity::Entity(Entity const & src)
{
    *this = src;
    return;
}


Entity::~Entity(void)
{
    return;
}

Entity::Entity(int num) : this->_character = '8';        // saving the charactor
{
    this->_object = new Entity[num];

    for (int i = 0; i < num ; i++) { 
        // flips time function here !!!
        shoot(this->_object[i], rand());     //// get random X number of window size and send though a copy
    }
}
/////////////////////////////////[  overloaded operators  ]////////////////////////////////////////

Entity& Entity::operator=(Entity const & rhs)
{
    if (this != &rhs)
    {
		this->_xLoc = rhs._xLoc;
		this->_yLoc = rhs._yLoc;
		this->_object = rhs._object;
        this->_character = rhs._character;
    }

    return *this;
}

/////////////////////////////////[  member functions  ]////////////////////////////////////////

int             *Entity::getlocation() 
{
    int    i[2];
    i[0] = this->_yLoc;
    i[1] = this->_xLoc;

    return(i);
}

void			Entity::setlocation(int x ,int y)
{
    this->_xloc = i[0];
    this->_yloc = i[1];
}



void    Entity::shoot(Entity object, int location)
{

    /*
    this->_xLoc = x;                                                //get maxwindow size function
    this->_yLoc = (rand(y) % y);
    */
    if ((hitPlayer() == false) && (hitBullet() == false))       // include bullets and player
    {
        this->_xLoc--;
    }
    if (this->xLoc == 0)
        setLocation(getmaxXlocation, location);                      // start loop again
}

bool        Entity::hitPlayer()
{
    int *pLoc = getplayerlocation();//get player location!!!!
    if (((this->xLoc == pLoc[0]) && (this->yloc == pLoc[1]))       // check for unit collision
    {
        delete this;
        return true
    }
    return false;
}

bool        Entity::hitBullet()
{
    int *pLoc = getlocation();//get player location!!!!
    if (((this->xLoc == pLoc[0]) && (this->yloc == pLoc[1]))       // check for Bullet collision
    {
        delete this;
        return true
    }
    return false;
}
