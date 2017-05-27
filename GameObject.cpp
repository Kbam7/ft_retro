/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:40:15 by kbamping          #+#    #+#             */
/*   Updated: 2017/05/28 00:54:58 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

GameObject::GameObject(void)
{
    return;
}

GameObject::GameObject(WINDOW * win)
{
    this->_character = '>';
    
	this->setWindow(win);
	setLocation(((yMax - 5) / 2), 2);
    // Get terminal size
	getmaxyx(this->_curwin, this->_yMax, this->_xMax);
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
		this->_xLoc = rhs._xLoc;
		this->_yLoc = rhs._yLoc;
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
    int *loc = this->getLocation(void);

	mvwaddch(this->_curwin, loc[1], loc[0], ' ');
	loc[1]--;
	if (loc[1] < 1)
		loc[1] = this->_yMax - 2;
}

void	GameObject::mvdown(void)
{
	mvwaddch(this->_curwin, this->_yLoc, this->_xLoc, ' ');
	this->_yLoc++;
	if (this->_yLoc > this->_yMax - 2)
		this->_yLoc = 1;
}

void	GameObject::mvleft(void)
{
	mvwaddch(this->_curwin, this->_yLoc, this->_xLoc, ' ');
	this->_xLoc--;
	this->_xLoc--;
	if (this->_xLoc < 1)
		this->_xLoc = 1;
}

void	GameObject::mvright(void)
{
	mvwaddch(this->_curwin, this->_yLoc, this->_xLoc,
    
	this->_xLoc++;
	this->_xLoc++;
	if (this->_xLoc > this->_xMax - 2)
		this->_xLoc = this->_xMax - 2;
}

int GameObject::getmv(void)
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
		default:
			break;
	}
	return (choice);
}

void	GameObject::displayGameObject(void)
{
	mvwaddch(this->_curwin, this->_yLoc, this->_xLoc, this->_character);
}

int     *GameObject::getLocation(void)
{
    return (this->_currLocation);
}

void    GameObject::setLocation(int xLoc, int yLoc)
{
    this->_currLocation[0] = xLoc;
    this->_some[1] = yLoc;
}

int     GameObject::getMax(char c)
{
    return ((c == 'x' ? this->_xMax : (c == 'y') ? this->_yMax : -1));
}

void    GameObject::setMax(char c, int val)
{
    if (val == 'x')
        this->_xLoc = val;
    else if (val == 'y')
        this->_yLoc = val;
}

WINDOW  *getWindow() const
{
    return (this->_curwin);
}

void    setWindow(WINDOW *win)
{
    this->_curwin = win;
}
    