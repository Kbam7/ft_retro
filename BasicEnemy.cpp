#include "BasicEnemy.hpp"


/////////////////////////////////[  constructor/destructor  ]////////////////////////////////////////

BasicEnemy::BasicEnemy(void)
{

}

BasicEnemy::BasicEnemy(BasicEnemy const & src)
{
    *this = src;
    return;
}


BasicEnemy::~BasicEnemy(void)
{
    return;
}

BasicEnemy::BasicEnemy(WINDOW * win, int xPos, int yPos) : GameObject::GameObject(win, 'B')
{
    //mvwaddch(this->getWindow(), this->getLocation('y') + 10, this->getLocation('x') + 10, '*');
    setLocation(xPos, yPos);
}
/////////////////////////////////[  overloaded operators  ]////////////////////////////////////////

BasicEnemy& BasicEnemy::operator=(BasicEnemy const & rhs)
{
    if (this != &rhs)
    {
		this->setLocation(rhs.getLocation('x'), rhs.getLocation('y'));
        this->setMax('x', rhs.getMax('x'));
		this->setMax('y', rhs.getMax('y'));
        this->setWindow(rhs.getWindow());
        this->_entities = rhs._entities;
        this->setCharacter(rhs.getCharacter());
        this->setAlive(rhs.isAlive());
    }

    return *this;
}



/*void    BasicEnemy::shoot(BasicEnemy object, int location)
{

}

bool        BasicEnemy::hitPlayer()
{

}*/
