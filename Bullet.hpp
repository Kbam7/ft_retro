/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 16:40:43 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 18:22:51 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BULLET_HPP_
#define _BULLET_HPP_

#include "GameObject.hpp"

class Bullet : public GameObject
{
	public:
		Bullet(void);
		Bullet(int x, int y);
		Bullet(Bullet const & src);
		Bullet& operator=(Bullet const & rhs);
		~Bullet(void);

		int		_xLoc;
		int		_yLoc;
        char	_character;
	private:

};

#endif