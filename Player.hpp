/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbromilo <rbromilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:53:27 by dmather           #+#    #+#             */
/*   Updated: 2017/05/27 23:25:06 by rbromilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <curses.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Player
{
	public:
		Player(void);
		Player(Player const & src);
		Player& operator=(Player const & rhs);
		~Player(void);

		Player(WINDOW * win, int _yMax);

		void	mvup();
		void	mvdown();
		void	mvleft();
		void	mvright();
		int		getmv();
		void	displayPlayer();
		
		WINDOW * curwin;

	private:
		int		_xLoc;
		int		_yLoc;
		int		_xMax;
		int		_yMax;
		char	_character;

};

#endif
