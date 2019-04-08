/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:14:41 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 14:14:46 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include "Point.class.hpp"
# include "retroDef.hpp"
# include "Bullet.class.hpp"

class Enemy1 : public Point {
	public:
		Enemy1(int, int);
		
		Enemy1(Enemy1 const &e);
		Enemy1();
		~Enemy1(void);
		Enemy1 & operator=(Enemy1 const &);
		
		static const std::string	s[];
		static const int			countStr;
		static const int			colorPair;
		void	changePositionBullets(Bullet *[]);
		int		isFacing(Bullet &);
	private:
		int		_numToChangePos;
		int		_numToShot;
};

#endif
