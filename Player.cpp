/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:29:07 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 00:54:57 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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