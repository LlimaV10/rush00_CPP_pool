/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:57:56 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 12:57:57 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include "Point.class.hpp"
# include "Enemy1.class.hpp"
# include "Enemy2.class.hpp"
# include "Boss.class.hpp"
# include "Bullet.class.hpp"
# include "retroDef.hpp"

class Player : public Point{
	public:
		Player(int, int);
		Player(Player const &);
		~Player(void);
		Player const & operator=(Player const &);
		int		isFacing(Enemy1 &);
		int		isFacing(Enemy2 &);
		int		isFacing(Bullet &);
		static std::string const	s[];
		static const int			countStr;
		static const int colorPair;
		
		void	move(int y, int x);
		void	shoot(Bullet *bullets[]);

		int		numToShoot;
	private:
};

#endif
