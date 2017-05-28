/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:53:27 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 10:37:44 by dmather          ###   ########.fr       */
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
#include <stdio.h>
#include <time.h>
#include <unistd.h>

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
//		void	add_score(unsigned int amount);
		
		WINDOW * curwin;
		static unsigned int	lives;
		static unsigned int	score;

	private:
		int		_xLoc;
		int		_yLoc;
		int		_xMax;
		int		_yMax;
		char	_character;

};

#endif
