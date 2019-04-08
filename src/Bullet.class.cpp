/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:00:43 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 15:00:44 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet(int x, int y, int vect, char symb) :
	Point(x, y), _vect(vect), _symb(symb), _numToChange(0) {
}

/*_________________________COPLIEN'S FORM___________________________________*/

Bullet::Bullet() {}

Bullet::~Bullet() {}

Bullet::Bullet(Bullet const &e) : Point(e._x, e._y) {
	*this = e;
}

Bullet & Bullet::operator=(Bullet const &e) {
	if (this != &e)
	{
		this->_x = e._x;
		this->_y = e._y;
		this->_vect = e.getVect();
		this->_symb = e.getSymb();
	}
	return *this;
}

/*______________________________________________________________________________*/

int	Bullet::getVect(void) const {
	return this->_vect;
}

int	Bullet::getSymb(void) const {
	return this->_symb;
}

void	Bullet::changePosition(void)
{
	if (this->_numToChange <= 0)
	{
		this->_numToChange = BULLET_CHANGE;
		this->_x += _vect;
	}
	else
		this->_numToChange--;
}
