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
		int	*loc = rhs.getLocation();
		setLocation(loc[0], loc[1]);
		setMax('x', rhs.getMax('x'));
		setMax('y', rhs.getMax('y'));
    }

    return *this;
}

Player::~Player(void)
{
    return;
}