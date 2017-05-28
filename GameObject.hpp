/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:53:27 by kbamping           #+#    #+#             */
/*   Updated: 2017/05/28 06:03:50 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GAME_OBJECT_HPP_
#define _GAME_OBJECT_HPP_

#include <curses.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

class GameObject {
public:
		GameObject(void);
        GameObject(WINDOW * win);
		GameObject(GameObject const & src);
		GameObject& operator=(GameObject const & rhs);
		~GameObject(void);

		

		void	mvup(void);
		void	mvdown(void);
		void	mvleft(void);
		void	mvright(void);
		int		getmv(void);
        void	displayGameObject(void);
        int     getLocation(char c) const;
        void    setLocation(int xLoc, int yLoc);
        int     getMax(char c) const;
        void    setMax(char c, int val);
        WINDOW  *getWindow() const;
        void    setWindow(WINDOW *win);
		bool	isAlive(void);
		void	setAlive(bool val);
        

private:
        int     _currLocation[2];
        int     _xMax;
        int     _yMax;
		char	_character;
		bool	_alive;
        WINDOW  *_curwin;

};

#endif /* _GAME_OBJECT_HPP_ */
