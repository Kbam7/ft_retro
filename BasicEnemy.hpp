/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicEnemy.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 11:53:06 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 11:53:09 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BASIC_ENEMY_HPP_
#define _BASIC_ENEMY_HPP_

#include "GameObject.hpp"


class BasicEnemy : public GameObject
{
	public:

BasicEnemy(void);
BasicEnemy(WINDOW * win, int xPos, int yPos);
BasicEnemy(BasicEnemy const & src);
BasicEnemy& operator=(BasicEnemy const & rhs);
~BasicEnemy(void);

/*
void    		shoot(BasicEnemy object, int location);          
bool         	hitPlayer();
bool         	hitBullet();*/

// have collision detection -- 

private:
	BasicEnemy  *_entities;
};

#endif
