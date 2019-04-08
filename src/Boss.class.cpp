/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:16:26 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/07 15:16:26 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.class.hpp"

const int Boss::countStr = 7;
const int Boss::colorPair = 2;

std::string const	Boss::s[Boss::countStr] = {
	"     ^<<<<",
	"   ^+- {",
	" ^-++=<<<<",
	"[=====<<",
	" v-++=<<<<",
	"   v+- {",
	"     v<<<<"
};

Boss::Boss(int x, int y) : Point(x, y), _numToChangePos(0), _numToShot(0), _health(25), _vectorX(-1), _vectorY(1) {
}

Boss::Boss(Boss const &e) : Point(e._x, e._y) {
	*this = e;
}

Boss::~Boss(void) {
}

Boss & Boss::operator=(Boss const &e) {
	if (this != &e)
	{
		this->_x = e._x;
		this->_y = e._y;
	}
	return *this;
}

void	Boss::changePositionBullets(Bullet *bullets[]) {
	if (this->_numToChangePos <= 0)
	{
		this->_numToChangePos = BOSS_CHANGE;
		this->_x += this->_vectorX;
		this->_y += this->_vectorY;
		if (this->_x < WINDOW_W / 2 || this->_x >= WINDOW_W - 1)
			this->_vectorX *= -1;
		if (this->_y <= 0 || this->_y >= WINDOW_H - 1)
			this->_vectorY *= -1;
	}
	else
		this->_numToChangePos -= 1;

	if (this->_numToShot <= 0)
	{
		this->_numToShot = BOSS_SHOOT_REPEAT;
		for (int i = 0; i < MAX_BULLETS_COUNT; i++)
			if (bullets[i] == 0)
			{
				bullets[i] = new Bullet(this->_x - 4, this->_y + 2, -1, 'C');
				break;
			}
		for (int i = 0; i < MAX_BULLETS_COUNT; i++)
			if (bullets[i] == 0)
			{
				bullets[i] = new Bullet(this->_x - 4, this->_y + 4, -1, 'C');
				break;
			}
	}
	else
		this->_numToShot -= 1;
}

int		Boss::isFacing(Bullet & bul)
{
	for (int ey = 0; ey < Boss::countStr; ey++) {
		for (size_t ex = 0; ex < Boss::s[ey].length(); ex++) {
			if (Boss::s[ey][ex] == ' ')
				continue;
			if (this->_x + static_cast<int>(ex) == bul.getX() && this->_y + ey == bul.getY())
				return 1;
		}
	}
	return 0;
}

void	Boss::takeDamage(void) {
	this->_health--;
}

int		Boss::getHealth(void) {
	return this->_health;
}
