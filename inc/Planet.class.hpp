/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Planet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:33:07 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/07 12:33:08 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANET_HPP
# define PLANET_HPP

# include "Point.class.hpp"
# include "retroDef.hpp"
# include <ncurses.h>
# include <cmath>

class Planet : public Point {
	public:
		Planet(int, int, int, int, int, int);
		
		Planet();
		Planet(Planet const &);
		~Planet(void);
		Planet & operator=(Planet const  &);

		int		getRadius(void)const;
		int		getVector(void)const;
		int		getMaxNumToChange(void)const; 
		int		getColorPair(void)const;
		void	changePosition(void);
		void	drawMe(WINDOW *_mainWin);
	private:
		int	_radius;
		int	_vector;
		int	_numToChange;
		int	_maxNumToChange;
		int	_colorPair;
};

#endif