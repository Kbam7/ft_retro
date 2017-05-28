/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 16:40:50 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 17:07:31 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

/////////////////////////////////[  constructor/destructor  ]////////////////////////////////////////

Bullet::Bullet(void)
{
    setCharacter('-');
    //shoot(*this);
}

Bullet::Bullet(int x, int y) : _xLoc(x), _yLoc(y)
{
    setCharacter('-');
    return;
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
		this->setLocation(rhs.getLocation('x'), rhs.getLocation('y'));
		this->setMax('x', rhs.getMax('x'));
		this->setMax('y', rhs.getMax('y'));
        this->setWindow(rhs.getWindow());
        this->setCharacter(rhs.getCharacter());
        this->setAlive(rhs.isAlive());
    }
    return *this;
}

/////////////////////////////////[  member functions  ]////////////////////////////////////////

