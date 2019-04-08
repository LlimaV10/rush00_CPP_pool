/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Retro.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:03:45 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 13:29:44 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Retro.class.hpp"

/*___________________COPLIEN`S FORM______________________________*/

Retro::Retro(void) : _numToSpawnEnemies(0), _numToSpawnPlanets(0), _prevTime(clock()), _countKills(0), _countLives(3) {
	int		i;

	for (i = 0; i < MAX_BULLETS_COUNT; i++)
		this->_bullets[i] = 0;
	for (i = 0; i < MAX_ENEMIES1_COUNT; i++)
		this->_enemies1[i] = 0;
	for (i = 0; i < MAX_ENEMIES2_COUNT; i++)
		this->_enemies2[i] = 0;
	for (i = 0; i < MAX_COUNT_PLANETS; i++)
		this->_planets[i] = 0;
	this->_boss = 0;
}

Retro::Retro(Retro const &ret) {
	*this = ret;
}

Retro::~Retro() {}

Retro & Retro::operator=(Retro const &ret) {
	int		i;

	if (this != &ret)
	{
		for (i = 0; i < MAX_BULLETS_COUNT; i++)
			this->_bullets[i] = ret._bullets[i];
		for (i = 0; i < MAX_ENEMIES1_COUNT; i++)
			this->_enemies1[i] = ret._enemies1[i];
		for (i = 0; i < MAX_ENEMIES2_COUNT; i++)
			this->_enemies2[i] = ret._enemies2[i];
		for (i = 0; i < MAX_COUNT_PLANETS; i++)
			this->_planets[i] = ret._planets[i];
		this->_boss = ret._boss;
		this->_countKills = ret._countKills;
		this->_countLives = ret._countLives;
	}
	return *this;
}

/*__________________________Methods________________________________*/

void	Retro::runGame(void)
{
	this->ncur = new Ncurses();
	this->player = new Player(3, 3);

	while (1)
	{
		while (clock() - this->_prevTime < DELAY)
			;
		this->_prevTime = clock();
		ncur->drawMainWin();
		ncur->drawBackgroundPlanets(this->_planets);
		ncur->drawSideWin(this->_countLives, this->_countKills);
		ncur->drawPlayer(*this->player);
		ncur->drawEnemies(_bullets, _enemies1, _enemies2, _boss);
		this->catchButton(getch());

		this->spawnEnemies();
		this->spawnPlanets();
		this->checkEnemiesCollisions();
		this->updateAll();
		this->player->numToShoot -= 1;
		ncur->drawBorders();
		ncur->refreshAll();
		if (!this->checkPlayerCollisions())
			this->_countLives--;
		if (this->_countLives <= 0) {
			ncur->exitMenu(FAIL);
			delete ncur;
			delete player;
			exit(0);
		}
		if (this->_countKills != 0 && this->_countKills % BOSS_SPAWNING_REPEAT == 0 && this->_boss == 0)
			this->_boss = new Boss(WINDOW_W - 3, WINDOW_H / 2);
	}

	delete ncur;
	delete player;
}

void	Retro::catchButton(int c){

	if (c == EXIT) {
		if (ncur->exitMenu(ESCAPE)) {
			delete ncur;
			delete player;
			exit(0);
		}
	}
	else if (c == 258)
		player->move(1, 0);
	else if (c == 259)
		player->move(-1, 0);
	else if (c == 260)
		player->move(0, -1);
	else if (c == 261)
		player->move(0, 1);
	else if (c == 112) {
		ncur->showPause();
		ncur->refreshAll();
		while (getch() != 112)
			;
	}
	else if (c == 32)
		this->player->shoot(this->_bullets);
}

void	Retro::updateAll(void) {
	int		i;

	for (i = 0; i < MAX_BULLETS_COUNT; i++)
		if (this->_bullets[i] != 0)
		{
			if (this->_bullets[i]->getX() < 0 || this->_bullets[i]->getX() >= WINDOW_W)
			{
				delete this->_bullets[i];
				this->_bullets[i] = 0;
			}
			else
				this->_bullets[i]->changePosition();
		}
	
	for (i = 0; i < MAX_ENEMIES1_COUNT; i++)
		if (this->_enemies1[i] != 0)
		{
			if (this->_enemies1[i]->getX() < 0)
			{
				delete this->_enemies1[i];
				this->_enemies1[i] = 0;
			}
			else
				this->_enemies1[i]->changePositionBullets(this->_bullets);
		}
	
	for (i = 0; i < MAX_ENEMIES2_COUNT; i++)
		if (this->_enemies2[i] != 0)
		{
			if (this->_enemies2[i]->getX() < 0)
			{
				delete this->_enemies2[i];
				this->_enemies2[i] = 0;
			}
			else
				this->_enemies2[i]->changePositionBullets(this->_bullets);
		}

	for (i = 0; i < MAX_COUNT_PLANETS; i++)
		if (this->_planets[i] != 0)
		{
			if (this->_planets[i]->getX() < -this->_planets[i]->getRadius())
			{
				delete this->_planets[i];
				this->_planets[i] = 0;
			}
			else
				this->_planets[i]->changePosition();
		}
	
	if (this->_boss != 0)
		this->_boss->changePositionBullets(this->_bullets);
}

int		Retro::checkPlayerCollisions(void) {
	int		i;

	for (i = 0; i < MAX_BULLETS_COUNT; i++)
		if (this->_bullets[i] != 0)
			if (this->player->isFacing(*this->_bullets[i])) {
				delete this->_bullets[i];
				this->_bullets[i] = 0;
				return 0;
			}
	
	for (i = 0; i < MAX_ENEMIES1_COUNT; i++)
		if (this->_enemies1[i] != 0)
			if (this->player->isFacing(*this->_enemies1[i])) {
				delete this->_enemies1[i];
				this->_enemies1[i] = 0;
				return 0;
			}

	for (i = 0; i < MAX_ENEMIES2_COUNT; i++)
		if (this->_enemies2[i] != 0)
			if (this->player->isFacing(*this->_enemies2[i])) {
				delete this->_enemies2[i];
				this->_enemies2[i] = 0;
				return 0;
			}
	return 1;
}

void	Retro::checkEnemiesCollisions(void) {
	int		i;
	int		j;

	for (i = 0; i < MAX_ENEMIES1_COUNT; i++)
		if (this->_enemies1[i] != 0)
			for (j = 0; j < MAX_BULLETS_COUNT; j++)
				if (this->_bullets[j] != 0 && this->_enemies1[i]->isFacing(*this->_bullets[j]))
				{
					delete this->_enemies1[i];
					this->_enemies1[i] = 0;
					if (this->_bullets[j]->getSymb() == '*')
						this->_countKills++;
					delete this->_bullets[j];
					this->_bullets[j] = 0;
					break;
				}

	for (i = 0; i < MAX_ENEMIES2_COUNT; i++)
		if (this->_enemies2[i] != 0)
			for (j = 0; j < MAX_BULLETS_COUNT; j++)
				if (this->_bullets[j] != 0 && this->_enemies2[i]->isFacing(*this->_bullets[j]))
				{
					delete this->_enemies2[i];
					this->_enemies2[i] = 0;
					if (this->_bullets[j]->getSymb() == '*')
						this->_countKills++;
					delete this->_bullets[j];
					this->_bullets[j] = 0;
					break;
				}

	if (this->_boss != 0)
	{
		for (j = 0; j < MAX_BULLETS_COUNT; j++)
			if (this->_bullets[j] != 0 && this->_boss->isFacing(*this->_bullets[j]))
			{
				this->_boss->takeDamage();
				delete this->_bullets[j];
				this->_bullets[j] = 0;
				break;
			}
		if (this->_boss->getHealth() <= 0)
		{
			delete this->_boss;
			this->_boss = 0;
			ncur->exitMenu(WIN);
			delete ncur;
			delete player;
			exit(0);
		}
	}
	
}

void	Retro::spawnEnemies(void) {
	int		i;
	int		j;

	if (this->_numToSpawnEnemies <= 0)
	{
		this->_numToSpawnEnemies = ENEMIES_SPAWNING_REPEAT;
		int		countToSpawn = MIN_SPAWNING_ENEMIES +
			(rand() % (MAX_SPAWNING_ENEMIES - MIN_SPAWNING_ENEMIES));
		for (i = 0; i < countToSpawn; i++)
		{
			int	enemyNumb = 1 + rand() % COUNT_DIFFERENT_ENEMIES;
			if (enemyNumb == 1)
			{
				for (j = 0; j < MAX_ENEMIES1_COUNT; j++)
					if (this->_enemies1[j] == 0)
					{
						this->_enemies1[j] = new Enemy1(WINDOW_W - 1, 
							1 + rand() % WINDOW_H - Enemy1::countStr);
						break;
					}
			}
			else if (enemyNumb == 2)
			{
				for (j = 0; j < MAX_ENEMIES2_COUNT; j++)
					if (this->_enemies2[j] == 0)
					{
						this->_enemies2[j] = new Enemy2(WINDOW_W - 1, 
							1 + rand() % WINDOW_H - Enemy1::countStr);
						break;
					}
			}
		}
	}
	else
		this->_numToSpawnEnemies--;
}

void	Retro::spawnPlanets(void) {
	if (this->_numToSpawnPlanets <= 0)
	{
		this->_numToSpawnPlanets = PLANETS_SPAWNNING_REPEAT;
		for (int i = 0; i < MAX_COUNT_PLANETS; i++) {
			if (this->_planets[i] == 0)
			{
				int		rad = 3 + rand() % 5;
				this->_planets[i] = new Planet(WINDOW_W + rad, rand() % WINDOW_H, -1, rad, 52 + rand() % 3, 3 + rand() % 5);
				break;
			}
		}
	}
	else
		this->_numToSpawnPlanets--;
}
