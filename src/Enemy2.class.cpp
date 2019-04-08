/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy2.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:32:02 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 17:32:02 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy2.class.hpp"

const int Enemy2::countStr = 3;
const int Enemy2::colorPair = 44;

std::string const	Enemy2::s[Enemy2::countStr] = {
	"   vv",
	"-----",
	"   ^^"
};

Enemy2::Enemy2(int x, int y) : Point(x, y), _numToChangePos(0), _numToShot(0) {
}

/*_____________________________COLPIEN'S FORM___________________________________*/

Enemy2::Enemy2(Enemy2 const &e) : Point(e._x, e._y) {
	*this = e;
}

Enemy2::Enemy2() {}

Enemy2::~Enemy2(void) {
}

Enemy2 & Enemy2::operator=(Enemy2 const &e) {
	if (this != &e)
	{
		this->_x = e._x;
		this->_y = e._y;
	}
	return *this;
}

/*_________________________________________________________________________________*/

void	Enemy2::changePositionBullets(Bullet *bullets[]) {
	if (this->_numToChangePos <= 0)
	{
		this->_numToChangePos = ENEMY2_CHANGE;
		this->_x -= 1;
	}
	else
		this->_numToChangePos -= 1;

	if (this->_numToShot <= 0)
	{
		this->_numToShot = ENEMY2_SHOOT_REPEAT;
		for (int i = 0; i < MAX_BULLETS_COUNT; i++)
			if (bullets[i] == 0)
			{
				bullets[i] = new Bullet(this->_x - 1, this->_y + 1, -2, '-');
				break;
			}
	}
	else
		this->_numToShot -= 1;
}

int		Enemy2::isFacing(Bullet & bul)
{
	for (int ey = 0; ey < Enemy2::countStr; ey++) {
		for (size_t ex = 0; ex < Enemy2::s[ey].length(); ex++) {
			if (Enemy2::s[ey][ex] == ' ')
				continue;
			if (this->_x + static_cast<int>(ex) == bul.getX() && this->_y + ey == bul.getY())
				return 1;
		}
	}
	return 0;
}
