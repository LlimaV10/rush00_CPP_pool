/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:16:23 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/07 15:16:25 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP
# define BOSS_HPP

# include <iostream>
# include "Point.class.hpp"
# include "retroDef.hpp"
# include "Bullet.class.hpp"

class Boss : public Point {
	public:
		Boss(int, int);
		Boss(Boss const &e);
		~Boss(void);
		Boss & operator=(Boss const &);
		static const std::string	s[];
		static const int			countStr;
		static const int			colorPair;
		void	changePositionBullets(Bullet *[]);
		int		isFacing(Bullet &);
		void	takeDamage(void);
		int		getHealth(void);
	private:
		int		_numToChangePos;
		int		_numToShot;
		int		_health;
		int		_vectorX;
		int		_vectorY;
};

#endif
