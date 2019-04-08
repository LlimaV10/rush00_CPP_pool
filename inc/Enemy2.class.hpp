/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy2.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:32:03 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 17:32:04 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY2_HPP
# define ENEMY2_HPP

# include <iostream>
# include "Point.class.hpp"
# include "retroDef.hpp"
# include "Bullet.class.hpp"

class Enemy2 : public Point {
	public:
		Enemy2(int, int);
		
		Enemy2();
		Enemy2(Enemy2 const &e);
		~Enemy2(void);
		Enemy2 & operator=(Enemy2 const &);

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
