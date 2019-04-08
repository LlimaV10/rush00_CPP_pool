/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:07:02 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 13:07:03 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.class.hpp"

/*_____________________COPLIEN`S FORM_____________________________*/

Ncurses::Ncurses() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	this->_mainWin = newwin(WINDOW_H, WINDOW_W, 1, 3);
	this->_sideWin = newwin(5, 30, WINDOW_H + 1, 3);

	box(this->_mainWin, 0, 0);
	box(this->_sideWin, 0, 0);

	nodelay(stdscr, true);

	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(42, COLOR_CYAN, COLOR_BLACK);
	init_pair(43, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(44, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
	init_pair(22, COLOR_CYAN, COLOR_CYAN);
	init_pair(23, COLOR_RED, COLOR_RED);

	init_pair(52, 240, COLOR_BLACK);
	init_pair(53, 0x11 , COLOR_BLACK);
	init_pair(54, 34, COLOR_BLACK);

	wborder(this->_mainWin, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(this->_sideWin, '|', '|', '-', '-', '+', '+', '+', '+');

	refresh();
	wrefresh(this->_mainWin);
	wrefresh(this->_sideWin);
}

Ncurses::~Ncurses() {

	delwin(this->_mainWin);
	delwin(this->_sideWin);
	endwin();
}

Ncurses::Ncurses(Ncurses const &e) {
	*this = e;
}

Ncurses & Ncurses::operator=(Ncurses const &e) {
	if (this != &e)
	{
		_mainWin = e._mainWin;
		_sideWin = e._sideWin;
	}
	return *this;
}

/*________________________METHODS______________________________*/

int		Ncurses::exitMenu(int state) {

	int c;
	if (state == ESCAPE) {

		wattron(_mainWin, COLOR_PAIR(42));
		mvwprintw(_mainWin, 25, 25, " .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ");
		mvwprintw(_mainWin, 26, 25, "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |");
		mvwprintw(_mainWin, 27, 25, "| |  _________   | || |  ____  ____  | || |     _____    | || |  _________   | || |    ______    | |");
		mvwprintw(_mainWin, 28, 25, "| | |_   ___  |  | || | |_  _||_  _| | || |    |_   _|   | || | |  _   _  |  | || |   / _ __ `.  | |");
		mvwprintw(_mainWin, 29, 25, "| |   | |_  \\_|  | || |   \\ \\  / /   | || |      | |     | || | |_/ | | \\_|  | || |  |_/____) |  | |");
		mvwprintw(_mainWin, 30, 25, "| |   |  _|  _   | || |    > `' <    | || |      | |     | || |     | |      | || |    /  ___.'  | |");
		mvwprintw(_mainWin, 31, 25, "| |  _| |___/ |  | || |  _/ /'`\\ \\_  | || |     _| |_    | || |    _| |_     | || |    |_|       | |");
		mvwprintw(_mainWin, 32, 25, "| | |_________|  | || | |____||____| | || |    |_____|   | || |   |_____|    | || |    (_)       | |");
		mvwprintw(_mainWin, 33, 25, "| |              | || |              | || |              | || |              | || |              | |");
		mvwprintw(_mainWin, 34, 25, "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |");
		mvwprintw(_mainWin, 35, 25, " '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ");
		mvwprintw(_mainWin, 36, 25, "                              'Q' TO EXIT OR 'SPACE' TO CONTINUE                                    ");
		wattroff(_mainWin, COLOR_PAIR(42));

		drawBorders();
		wrefresh(_mainWin);

		while (1) {
			c = getch();
			if (c == EXIT)
				return (1);
			else if (c == SPACE)
				return (0);
		}
	}
	else if (state == FAIL) {

		wattron(_mainWin, COLOR_PAIR(2));
		mvwprintw(_mainWin, 25, 25, "  @@@@@    @ @@    @ @   @@  @ @@@@@       @@@@@    @    @  @ @@@@  @ @@@  ");
		mvwprintw(_mainWin, 26, 25, " @     @   @  @@   @  @ @ @  @            @     @   @    @  @       @    @ ");
		mvwprintw(_mainWin, 27, 25, "@          @    @  @   @  @  @           @       @  @    @  @       @    @ ");
		mvwprintw(_mainWin, 28, 25, "@          @ @@@@  @      @  @ @@@@@     @       @  @    @  @ @@@@  @ @@@  ");
		mvwprintw(_mainWin, 29, 25, "@    @@@@  @    @  @      @  @           @       @  @    @  @       @   @  ");
		mvwprintw(_mainWin, 30, 25, " @     @   @    @  @      @  @            @     @    @   @  @       @    @ ");
		mvwprintw(_mainWin, 31, 25, "  @@@@@    @    @  @      @  @ @@@@@       @@@@@      @@@   @ @@@@  @     @");
		mvwprintw(_mainWin, 32, 25, "                           'Q' TO EXIT                                     ");
		wattroff(_mainWin, COLOR_PAIR(2));
		drawBorders();
		wrefresh(_mainWin);

		while (1) {
			c = getch();
			if (c == EXIT)
				break;
		}
	}
	else if (state == WIN) {
		wattron(_mainWin, COLOR_PAIR(2));
		mvwprintw(_mainWin, 25, 25, "$$\\     $$\\                                       $$\\           $$\\   ");
		mvwprintw(_mainWin, 26, 25, "\\$$\\   $$  |                                      \\__|          $$ |");
		mvwprintw(_mainWin, 27, 25, " \\$$\\ $$  /$$$$$$\\  $$\\   $$\\       $$\\  $$\\  $$\\ $$\\ $$$$$$$\\  $$ |");
		mvwprintw(_mainWin, 28, 25, "  \\$$$$  /$$  __$$\\ $$ |  $$ |      $$ | $$ | $$ |$$ |$$  __$$\\ $$ |");
		mvwprintw(_mainWin, 29, 25, "   \\$$  / $$ /  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ |$$ |  $$ |\\__|");
		mvwprintw(_mainWin, 30, 25, "    $$ |  $$ |  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ |$$ |  $$ |    ");
		mvwprintw(_mainWin, 31, 25, "    $$ |  \\$$$$$$  |\\$$$$$$  |      \\$$$$$\\$$$$  |$$ |$$ |  $$ |$$\\");
		mvwprintw(_mainWin, 32, 25, "    \\__|   \\______/  \\______/        \\_____\\____/ \\__|\\__|  \\__|\\__|");
		mvwprintw(_mainWin, 33, 25, "                           Q' TO EXIT                                   ");
		wattroff(_mainWin, COLOR_PAIR(2));
		drawBorders();
		wrefresh(_mainWin);

		while (1) {
			c = getch();
			if (c == EXIT)
				break;
		}
	}
	return (0);
}

void	Ncurses::drawMainWin(){

	int i, j, t;
	i = 0;
	wattron(_mainWin, COLOR_PAIR(1));
	while (++i < WINDOW_H)
	{
		mvwprintw(_mainWin, i, 1, " ");
		j = 0;
		t = i % 2;
		while (++j < WINDOW_W) {
			if (j % 2 == 0)
				mvwprintw(_mainWin, i, j + t, ".");
			else
				mvwprintw(_mainWin, i, j + t, " ");
		}
	}
	wattroff(_mainWin, COLOR_PAIR(1));
}

void	Ncurses::drawBackgroundPlanets(Planet *planets[]) {
	for (int i = 0; i < MAX_COUNT_PLANETS; i++)
		if (planets[i] != 0)
			planets[i]->drawMe(this->_mainWin);
}

void	Ncurses::drawSideWin(int lives, int score) {

	wattron(_sideWin, COLOR_PAIR(3));
	mvwprintw(_sideWin, 1, 1, "LIVES ");
	wattroff(_sideWin, COLOR_PAIR(3));

	wattron(_sideWin, COLOR_PAIR(2));
	mvwprintw(_sideWin, 1, 7, "%d ", lives);
	wattroff(_sideWin, COLOR_PAIR(2));

	wattron(_sideWin, COLOR_PAIR(44));
	mvwprintw(_sideWin, 2, 1, "SCORE %d  ", score);
	wattroff(_sideWin, COLOR_PAIR(44));

	wattron(_sideWin, COLOR_PAIR(3));
	mvwprintw(_sideWin, 1, 21, "PLAYING");
	wattroff(_sideWin, COLOR_PAIR(3));

	wattron(_sideWin, COLOR_PAIR(42));
	mvwprintw(_sideWin, 2, 17, "TIME: %d:%d:%d ", (clock() / CLOCKS_PER_SEC) / 60, clock() / CLOCKS_PER_SEC, (clock() * 60 / CLOCKS_PER_SEC) % 60);
	wattroff(_sideWin, COLOR_PAIR(42));
}

void	Ncurses::showPause() {
	wattron(_sideWin, COLOR_PAIR(43));
	mvwprintw(_sideWin, 1, 21, "PAUSE   ");
	wattroff(_sideWin, COLOR_PAIR(43));
}

void	Ncurses::drawBorders() {

	wborder(_mainWin, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(_sideWin, '|', '|', '-', '-', '/', '\\', '\\', '/');
}

void Ncurses::drawPlayer(Player &player) {

	wattron(_mainWin, COLOR_PAIR(Player::colorPair));
	for (int py = 0; py < Player::countStr; py++) {
		for (size_t px = 0; px < Player::s[py].length(); px++) {
			if (Player::s[py][px] == ' ')
				;
			else
				mvwprintw(_mainWin, player.getY() + py, player.getX() + px, "%c", Player::s[py][px]);
		}
	}
	wattroff(_mainWin, COLOR_PAIR(player.colorPair));
}

void Ncurses::drawEnemy1(Enemy1 &enemy) {

	wattron(_mainWin, COLOR_PAIR(enemy.colorPair));
	for (int py = 0; py < enemy.countStr; py++) {
		for (size_t px = 0; px < enemy.s[py].length(); px++) {
			if (Enemy1::s[py][px] == ' ')
				;
			else
				mvwprintw(_mainWin, enemy.getY() + py, enemy.getX() + px, "%c", Enemy1::s[py][px]);
		}
	}
	wattroff(_mainWin, COLOR_PAIR(enemy.colorPair));
}

void Ncurses::drawEnemy2(Enemy2 &enemy) {

	wattron(_mainWin, COLOR_PAIR(enemy.colorPair));
	for (int py = 0; py < enemy.countStr; py++) {
		for (size_t px = 0; px < enemy.s[py].length(); px++) {
			if (Enemy2::s[py][px] == ' ')
				;
			else
				mvwprintw(_mainWin, enemy.getY() + py, enemy.getX() + px, "%c", Enemy2::s[py][px]);
		}
	}
	wattroff(_mainWin, COLOR_PAIR(enemy.colorPair));
}

void Ncurses::drawBoss(Boss &enemy) {

	wattron(_mainWin, COLOR_PAIR(enemy.colorPair));
	for (int py = 0; py < enemy.countStr; py++) {
		for (size_t px = 0; px < enemy.s[py].length(); px++) {
			if (Boss::s[py][px] == ' ')
				;
			else
				mvwprintw(_mainWin, enemy.getY() + py, enemy.getX() + px, "%c", Boss::s[py][px]);
		}
	}
	wattroff(_mainWin, COLOR_PAIR(enemy.colorPair));
}

void	Ncurses::drawEnemies(Bullet	*_bullets[],	Enemy1	*_enemies1[], Enemy2 *_enemies2[], Boss *_boss) {

	for (unsigned int i = 0; i < MAX_BULLETS_COUNT; i++) {
		if (_bullets[i]) {
			wattron(_mainWin, COLOR_PAIR(11));
			mvwprintw(_mainWin, _bullets[i]->getY(), _bullets[i]->getX(), "%c", _bullets[i]->getSymb());
			wattroff(_mainWin, COLOR_PAIR(11));
			}
	}

	for (unsigned int i = 0; i < MAX_ENEMIES1_COUNT; i++) {
		if (_enemies1[i])
			drawEnemy1(*_enemies1[i]);
	}

	for (unsigned int i = 0; i < MAX_ENEMIES2_COUNT; i++) {
		if (_enemies2[i] != 0)
			drawEnemy2(*_enemies2[i]);	
	}

	if (_boss != 0)
		drawBoss(*_boss);
}

void	Ncurses::refreshAll()
{
	drawBorders();
	wrefresh(_mainWin);
	wrefresh(_sideWin);	
}

void	Ncurses::print(int i, int j, int n, char *win) {

	

	if (strcmp(win, "_mainWin") == 0) {
		wattron(_mainWin, COLOR_PAIR(2));
		mvwprintw(_mainWin, i, j, "%3d", n);
		wattroff(_mainWin, COLOR_PAIR(2));
		}
	else {
		wattron(_sideWin, COLOR_PAIR(2));
		mvwprintw(_sideWin, i, j, "%3d", n);
		wattroff(_sideWin, COLOR_PAIR(2));
	}
	
}

