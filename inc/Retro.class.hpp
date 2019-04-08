/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Retro.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:03:43 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 13:03:44 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRO_CLASS_HPP
# define RETRO_CLASS_HPP

# include <iostream>
# include "Ncurses.class.hpp"
# include <ctime>

class Retro {
	public:
		Retro(void);
		Retro(Retro const &);
		~Retro();
		Retro & operator=(Retro const &);

	Ncurses	*ncur;
	Player	*player;

	void	runGame(void);
	void	catchButton(int c);

	private:
		void	updateAll(void);
		void	spawnEnemies(void);
		void	spawnPlanets(void);
		int		checkPlayerCollisions(void);
		void	checkEnemiesCollisions(void);
		Bullet	*_bullets[MAX_BULLETS_COUNT];
		Enemy1	*_enemies1[MAX_ENEMIES1_COUNT];
		Enemy2	*_enemies2[MAX_ENEMIES2_COUNT];
		Boss	*_boss;
		int		_numToSpawnEnemies;
		Planet	*_planets[MAX_COUNT_PLANETS];
		int		_numToSpawnPlanets;
		clock_t	_prevTime;
		int		_countKills;
		int		_countLives;
};

#endif
