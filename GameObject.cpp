/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:40:15 by kbamping          #+#    #+#             */
/*   Updated: 2017/05/28 17:47:14 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Bullet.hpp"

GameObject::GameObject(void)
{
    return;
}

GameObject::GameObject(WINDOW * win, char ch)
{
    this->_character = ch;
	this->_alive = true;
	this->_lastSpawnTime = 0;
    
	this->setWindow(win);
    // Listen to keypad
	keypad(this->_curwin, true);
}

GameObject::GameObject(GameObject const & src)
{
    *this = src;
    return;
}

GameObject& GameObject::operator=(GameObject const & rhs)
{
    if (this != &rhs)
    {
		this->_currLocation[0] = rhs._currLocation[0];
		this->_currLocation[1] = rhs._currLocation[1];
        this->_xMax = rhs._xMax;
		this->_yMax = rhs._yMax;
		this->_character = rhs._character;
    }

    return *this;
}

GameObject::~GameObject(void)
{
    return;
}

void	GameObject::mvup(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
	this->_currLocation[1]--;
	if (this->_currLocation[1] < 1)
		this->_currLocation[1] = this->_yMax - 2;
}

void	GameObject::mvdown(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
	this->_currLocation[1]++;
	if (this->_currLocation[1] > this->_yMax - 2)
		this->_currLocation[1] = 1;
}

void	GameObject::mvleft(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
	this->_currLocation[0]--;
	this->_currLocation[0]--;
	if (this->_currLocation[0] < 1)
		this->_currLocation[0] = 1;
}

void	GameObject::mvright(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
    
	this->_currLocation[0]++;
	this->_currLocation[0]++;
	if (this->_currLocation[0] > this->_xMax - 2)
		this->_currLocation[0] = this->_xMax - 2;
}

void	GameObject::shoot(long int microsec)
{
//	Bullet *b = new Bullet(this->_currLocation[0], this->_currLocation[1]);
//	b->setLocation(this->_currLocation[0], this->_currLocation[1]);
	if (microsec)
	{}
//	mvwaddch(this->_curwin, b->getLocation('y'), ++b->_xLoc, '-');	
}

int GameObject::getmv(long int	microsec)
{
	int	choice = wgetch(this->_curwin);
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
		case 32:
			shoot(microsec);
			break;
		default:
			break;
	}
	return (choice);
}

void	GameObject::displayGameObject(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], this->_character);
}

int		GameObject::getLocation(char c) const
{
	if (c == 'x')
    	return (this->_currLocation[0]);
	else if (c == 'y')
    	return (this->_currLocation[1]);
	else
		return (-1);
}

void    GameObject::setLocation(int xLoc, int yLoc)
{
	if (xLoc == -1)
    	xLoc = this->_currLocation[0];
	if (yLoc == -1)
		yLoc = this->_currLocation[1];

	this->_currLocation[0] = xLoc;	
    this->_currLocation[1] = yLoc;
}

int     GameObject::getMax(char c) const
{
    return ((c == 'x' ? this->_xMax : (c == 'y') ? this->_yMax : -1));
}

void    GameObject::setMax(char c, int val)
{
    if (c == 'x')
        this->_xMax = val;
    else if (c == 'y')
        this->_yMax = val;
}

WINDOW  *GameObject::getWindow() const
{
    return (this->_curwin);
}

void    GameObject::setWindow(WINDOW *win)
{
    this->_curwin = win;
}

bool	GameObject::isAlive(void) const
{
	return ((this->_alive ? true : false));
}

void	GameObject::setAlive(bool val)
{
	this->_alive = val;
}

char    GameObject::getCharacter(void) const
{
	return (this->_character);
}

void    GameObject::setCharacter(char c)
{
	if (c > '\0')
		this->_character = c;
}