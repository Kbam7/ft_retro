#include "Player.hpp"


Player::Player(void)
{
    return;
}

Player::Player(WINDOW * win) : GameObject::GameObject(win)
{

}

Player::Player(Player const & src)
{
    *this = src;
    return;
}

Player& Player::operator=(Player const & rhs)
{
    if (this != &rhs)
    {
		setLocation(rhs.getLocation('x'), rhs.getLocation('y'));
		setMax('x', rhs.getMax('x'));
		setMax('y', rhs.getMax('y'));
    }

    return *this;
}

Player::~Player(void)
{
    return;
}
