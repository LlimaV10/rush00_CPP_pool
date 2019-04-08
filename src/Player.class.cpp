/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:57:57 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 12:57:58 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

const int Player::countStr = 3;
const int Player::colorPair = 42;

std::string const	Player::s[Player::countStr] = {
	"}}>",
	" }>->",
	"}}>"
};


Player::Player(int x, int y) : Point(x, y), numToShoot(0) {
}

Player::Player(Player const &e) : Point(e._x, e._y) {
	*this = e;
}

Player::~Player(void) {
}

Player const & Player::operator=(Player const &e) {
	if (this != &e)
	{
		this->_x = e._x;
		this->_y = e._y;
	}
	return *this;
}

int		Player::isFacing(Enemy1 &e)
{
	for (int py = 0; py < Player::countStr; py++) {
		for (size_t px = 0; px < Player::s[py].length(); px++) {
			if (Player::s[py][px] == ' ')
				continue;
			for (int ey = 0; ey < Enemy1::countStr; ey++) {
				for (size_t ex = 0; ex < Enemy1::s[ey].length(); ex++) {
					if (Enemy1::s[ey][ex] == ' ')
						continue;
					if (py + this->_y == ey + e.getY() && px + this->_x == ex + e.getX())
						return 1;

				}
			}
		}
	}
	return 0;
}

int		Player::isFacing(Enemy2 &e)
{
	for (int py = 0; py < Player::countStr; py++) {
		for (size_t px = 0; px < Player::s[py].length(); px++) {
			if (Player::s[py][px] == ' ')
				continue;
			for (int ey = 0; ey < Enemy2::countStr; ey++) {
				for (size_t ex = 0; ex < Enemy2::s[ey].length(); ex++) {
					if (Enemy2::s[ey][ex] == ' ')
						continue;
					if (py + this->_y == ey + e.getY() && px + this->_x == ex + e.getX())
						return 1;

				}
			}
		}
	}
	return 0;
}

int		Player::isFacing(Bullet &bul)
{
	for (int py = 0; py < Player::countStr; py++) {
		for (size_t px = 0; px < Player::s[py].length(); px++) {
			if (Enemy1::s[py][px] == ' ')
				continue;
			if (py + this->_y == bul.getY() && static_cast<int>(px) + this->_x == bul.getX())
				return 1;
		}
	}
	return 0;
}


void	Player::move(int y, int x)
{
	if ((_x + x) > 0 && (_x + x) < WINDOW_W - 3)
		_x += x;
	if ((_y + y) > 0 && (_y + y) < WINDOW_H - 3)
		_y += y;
}

void	Player::shoot(Bullet *bullets[])
{
	if (this->numToShoot > 0)
		return;
	this->numToShoot = PLAYER_SHOOT_CHANGE;
	for (int i = 0; i < MAX_BULLETS_COUNT; i++)
		if (bullets[i] == 0)
		{
			bullets[i] = new Bullet(this->_x + 5, this->_y + 1, 2, '*');
			break;
		}
}
