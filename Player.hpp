/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:53:27 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 00:55:28 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

# include "GameObject.hpp"

class Player : public GameObject {
	public:
		Player(void);
		Player(WINDOW * win);
		Player(Player const & src);
		Player& operator=(Player const & rhs);
		~Player(void);

};

#endif
