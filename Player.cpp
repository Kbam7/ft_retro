/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:29:07 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 16:08:20 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"


Player::Player(void)
{
    return;
}

Player::Player(WINDOW * win) : GameObject::GameObject(win, '>')
{
    int x;
    int y;
    
    // Get terminal size
	getmaxyx(this->getWindow(), y, x);
    this->setMax('x', x);
    this->setMax('y', y);
    setLocation(2, ((this->getMax('y')) / 2));
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
		this->setLocation(rhs.getLocation('x'), rhs.getLocation('y'));
		this->setMax('x', rhs.getMax('x'));
		this->setMax('y', rhs.getMax('y'));
        this->setWindow(rhs.getWindow());
        this->setCharacter(rhs.getCharacter());
        this->setAlive(rhs.isAlive());
    }
    return *this;
}

Player::~Player(void)
{
    return;
}
