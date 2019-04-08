/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:07:01 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 13:07:02 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <ncurses.h>
# include "Player.class.hpp"
# include "retroDef.hpp"
# include "Bullet.class.hpp"
# include "Planet.class.hpp"

class Ncurses {
	public:
		Ncurses(void);
		Ncurses(Ncurses const &src);
		~Ncurses();
		Ncurses &operator=(Ncurses const &);
		
	void	drawMainWin();
	void	drawSideWin(int lives, int score);
	void	drawPlayer(Player &player);
	void	refreshAll();
	void	print(int i, int j, int n, char *win);
	void	drawEnemies(Bullet	*_bullets[],	Enemy1	*_enemies1[],
		Enemy2	*_enemies2[], Boss *_boss);
	void	drawEnemy1(Enemy1 &enemy);
	void	drawEnemy2(Enemy2 &enemy);
	void	drawBoss(Boss &enemy);
	void	drawBorders();
	void	showPause();
	int		exitMenu(int state);

	void	drawBackgroundPlanets(Planet *planets[]);

	private:
		WINDOW	*_mainWin;
		WINDOW	*_sideWin;

};

#endif
