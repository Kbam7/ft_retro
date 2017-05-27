/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:53:27 by kbamping           #+#    #+#             */
/*   Updated: 2017/05/27 21:34:10 by kbamping         ###   ########.fr       */
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
        int     *getLocation(void) const;
        void    setLocation(int xLoc, int yLoc);
        int     getMax(char c) const;
        void    setMax(char c, int val);
        WINDOW  *getWindow() const;
        void    setWindow(WINDOW *win);
        

private:
        int     *_currLocation;
        int     _xMax;
        int     _yMax;
		char	_character;
        WINDOW  *_curwin;

};

#endif /* _GAME_OBJECT_HPP_ */