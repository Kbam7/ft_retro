/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:29:07 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 10:15:23 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"


Player::Player(void)
{
    return;
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
		this->_xLoc = rhs._xLoc;
		this->_yLoc = rhs._yLoc;
		this->_xMax = rhs._xMax;
		this->_yMax = rhs._yMax;
		this->_character = rhs._character;
    }

    return *this;
}

Player::~Player(void)
{
    return;
}

Player::Player(WINDOW * win, int yMax)
{
	curwin = win;
	this->_yLoc = (yMax - 5) / 2;
	this->_xLoc = 2;
	getmaxyx(curwin, this->_yMax, this->_xMax);
	keypad(curwin, true);
	this->_character = '>';
}
/*
void	Player::add_score(unsigned int amount)
{
	this->score += amount;
//	mvwprintw(infowin, 1, 7, "%i", this->score);
}*/

void	Player::mvup()
{
	mvwaddch(curwin, this->_yLoc, this->_xLoc, ' ');
	this->_yLoc--;
	if (this->_yLoc < 1)
		this->_yLoc = this->_yMax - 2;
}

void	Player::mvdown()
{
	mvwaddch(curwin, this->_yLoc, this->_xLoc, ' ');
	this->_yLoc++;
	if (this->_yLoc > this->_yMax - 2)
		this->_yLoc = 1;
}

void	Player::mvleft()
{
	mvwaddch(curwin, this->_yLoc, this->_xLoc, ' ');
	this->_xLoc--;
	this->_xLoc--;
	if (this->_xLoc < 1)
		this->_xLoc = 1;
}

void	Player::mvright()
{
	mvwaddch(curwin, this->_yLoc, this->_xLoc, ' ');
	this->_xLoc++;
	this->_xLoc++;
	if (this->_xLoc > this->_xMax - 2)
		this->_xLoc = this->_xMax - 2;
}

int Player::getmv()
{
	int	choice = wgetch(curwin);
	switch(choice)
	{
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		default:
			break;
	}
	return (choice);
}

void	Player::displayPlayer()
{
	mvwaddch(curwin, this->_yLoc, this->_xLoc, this->_character);
}
