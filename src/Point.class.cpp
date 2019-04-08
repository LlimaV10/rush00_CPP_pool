/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:16:05 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 14:16:05 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

Point::Point(int x, int y) : _x(x), _y(y){
}

/*_________________________COPLIEN'S FORM___________________________________*/

Point::Point() {}

Point::Point(Point const &p) {
	*this = p;
}

Point::~Point(void) {
}

Point & Point::operator=(Point const &p) {
	if (this != &p)
	{
		this->_x = p._x;
		this->_y = p._y;
	}
	return *this;
}

/*______________________________________________________________________________*/

int  Point::getX() const {
	return this->_x;
}

int  Point::getY() const {
	return this->_y;
}

