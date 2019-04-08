/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:14:40 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 14:14:41 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy1.class.hpp"

const int Enemy1::countStr = 5;
const int Enemy1::colorPair = 43;

std::string const	Enemy1::s[Enemy1::countStr] = {
	"   ^<",
	"  ^^<",
	"{--|<<",
	"  vv<",
	"   v<"
};

Enemy1::Enemy1(int x, int y) : Point(x, y), _numToChangePos(0), _numToShot(0) {
}

/*____________________________COPLIEN'S FORM___________________________________*/

Enemy1::Enemy1() {}

Enemy1::Enemy1(Enemy1 const &e) : Point(e._x, e._y) {
	*this = e;
}

Enemy1::~Enemy1(void) {
}

Enemy1 & Enemy1::operator=(Enemy1 const &e) {
	if (this != &e)
	{
		this->_x = e._x;
		this->_y = e._y;
	}
	return *this;
}

/*_____________________________________________________________________________*/

void	Enemy1::changePositionBullets(Bullet *bullets[]) {
	if (this->_numToChangePos <= 0)
	{
		this->_numToChangePos = ENEMY1_CHANGE;
		this->_x -= 1;
	}
	else
		this->_numToChangePos -= 1;

	if (this->_numToShot <= 0)
	{
		this->_numToShot = ENEMY1_SHOOT_REPEAT;
		for (int i = 0; i < MAX_BULLETS_COUNT; i++)
			if (bullets[i] == 0)
			{
				bullets[i] = new Bullet(this->_x - 1, this->_y + 2, -1, 'o');
				break;
			}
	}
	else
		this->_numToShot -= 1;
}

int		Enemy1::isFacing(Bullet & bul)
{
	for (int ey = 0; ey < Enemy1::countStr; ey++) {
		for (size_t ex = 0; ex < Enemy1::s[ey].length(); ex++) {
			if (Enemy1::s[ey][ex] == ' ')
				continue;
			if (this->_x + static_cast<int>(ex) == bul.getX() && this->_y + ey == bul.getY())
				return 1;
		}
	}
	return 0;
}
