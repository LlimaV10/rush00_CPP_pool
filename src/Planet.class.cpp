/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Planet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:33:04 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/07 12:33:05 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Planet.class.hpp"

Planet::Planet(int x, int y, int vect, int radius, int colorPair, int maxNumToChange) : Point(x, y),
	_radius(radius), _vector(vect), _numToChange(0),
	_maxNumToChange(maxNumToChange), _colorPair(colorPair) {
}


/*______________________________COPIEN'S FORM______________________________________*/

Planet::Planet() {}

Planet::~Planet(void) {
}

Planet::Planet(Planet const &pl) : Point(pl.getX(), pl.getY()), _numToChange(0) {
	*this = pl;
}

Planet & Planet::operator=(Planet const &pl) {
	if (this != &pl)
	{
		this->_radius = pl.getRadius();
		this->_vector = pl.getVector();
		this->_maxNumToChange = pl.getMaxNumToChange();
		this->_colorPair = pl.getColorPair();
		this->_x = pl.getX();
		this->_y = pl.getY();
	}
	return *this;
}

/*_________________________________________________________________________________*/

int		Planet::getRadius(void) const {
	return this->_radius;
}
int		Planet::getVector(void) const {
	return this->_vector;
}
int		Planet::getMaxNumToChange(void) const {
	return this->_maxNumToChange;
}
int		Planet::getColorPair(void) const {
	return this->_colorPair;
}

void	Planet::changePosition(void) {
	if (this->_numToChange <= 0)
	{
		this->_numToChange = this->_maxNumToChange;
		this->_x += this->_vector;
	}
	else
		this->_numToChange--;
}

void	Planet::drawMe(WINDOW *_mainWin) {
	int		x;
	int		y;

	wattron(_mainWin, COLOR_PAIR(this->_colorPair));
	for (x = -this->_radius * 2; x < this->_radius * 2; x++) {
		y = sqrt(this->_radius * this->_radius - x * x / 4);
		for (int i = this->_y - y; i < this->_y + y; i++) {
			if (i >= 0 && i < WINDOW_H && this->_x + x >= 0 && this->_x + x < WINDOW_W)
				mvwprintw(_mainWin, i, this->_x + x, "0");
		}
	}
	wattroff(_mainWin, COLOR_PAIR(this->_colorPair));
}