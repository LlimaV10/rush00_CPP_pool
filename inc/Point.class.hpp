/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:16:06 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 14:16:07 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

class Point {
	public:
		Point(int, int);
		
		Point();
		Point(Point const &);
		~Point(void);
		Point & operator=(Point const &);
		
		int getX() const;
		int getY() const;

	protected:
		int	_x;
		int	_y;
};

#endif
