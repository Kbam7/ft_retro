/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:40:48 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 12:52:45 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Player.hpp"
#include "BasicEnemy.hpp"

#define	MAX_ENEMY 20
/*
void	updateDisplay(void);
bool	objectsCollide(void);*/

static long int	sec;

void game_clock(WINDOW * infowin)
{
	static time_t	clock_start = 0;
	time_t			result = 0;

	result = time(NULL);
	if (clock_start == 0)
		clock_start = result;
	else
	{
		sec = result - clock_start;
		mvwprintw(infowin, 1, 12, "%li", sec);
	}
}

int	main()
{
	initscr();
	noecho();
	cbreak();								// raw();
	curs_set(0);
	nodelay(stdscr, true);

	std::string	choices[2] = {"play", "exit"};
	int			choice;
	int			highlight = 0;

	while (1)
	{
		// get screen size
		int yMax, xMax;
		getmaxyx(stdscr, yMax, xMax);
		if (xMax < 50)
			xMax = 50;
		if (yMax < 20)
			yMax = 20;
		if (xMax > 150)
			xMax = 150;
		if (yMax > 50)
			yMax = 50;

		clear();
		//	creates a window for our input
		WINDOW * menuwin = newwin(4, 7, (yMax/2) - 2, (xMax/2) - 2);
		box(menuwin, 0, 0);
		refresh();
		wrefresh(menuwin);

		keypad(menuwin, true);

		for (int i = 0; i < 2; i++)
		{
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i+1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);

		switch(choice)
		{
			case KEY_UP:
				highlight--;
				if (highlight == -1)
					highlight = 1;
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight == 2)
					highlight = 0;
				break;
			default:
				break;
		}
		if (choice == 10)
		{
			if (choices[highlight] == "exit")
			{
				endwin();
				return (0);
			}
			else if (choices[highlight] == "play")
			{
				delwin(menuwin);
				endwin();
				refresh();

				WINDOW * infowin = newwin(5, xMax, 0, 0);
				box(infowin, 0, 0);
				wrefresh(infowin);

				WINDOW * gamewin = newwin(yMax - 5, xMax, 5, 0);
				box(gamewin, 0, 0);
				nodelay(gamewin, true);
				wrefresh(gamewin);

				getmaxyx(gamewin, yMax, xMax);

				refresh();

				Player * p = new Player(gamewin);
				BasicEnemy * e[MAX_ENEMY];
				srand(time(0));
				int y;
				for (int x = 0; x < MAX_ENEMY; ++x)
				{
					y = (rand() % yMax);
					if (y >= yMax - 1)
						y = yMax - 2;
					else if (y < 1)
						y = 1;

					 e[x] = new BasicEnemy(gamewin, xMax - 2, y);
				}

				do {
					//updateDisplay();


				for (int i = 0 ; i < MAX_ENEMY; i++) {
					if (e[i]->isAlive())
						e[i]->displayGameObject();
				}
				if (p->isAlive())
					p->displayGameObject();
					

					mvwprintw(infowin, 1, 1, "Game Time: ");
					mvwprintw(infowin, 2, 1, "Score: ");
					mvwprintw(infowin, 3, 1, "Lives: ");
					game_clock(infowin);
					wrefresh(infowin);
					wrefresh(gamewin);
					refresh();
				} while (p->getmv() != 27);

				delwin(gamewin);
				delwin(infowin);
				endwin();
				continue;
			}
		}
	}
	return (0);
}
/*
void	updateDisplay(void) {
	for (int i = 0 ;i < 5; i++) {
		if (e[i].isAlive())
			e[i].displayGameObject();
	}
	if (p.isAlive())
		p.displayGameObject();
}

bool	objectsCollide(void) {
	int	playerLoc[2], enemyLoc[2];

	playerLoc[0] = Game::player->getLocation('x');
	playerLoc[1] = Game::player->getLocation('y');
	// Check enemies
	for (int i = 0 ;i < 5; i++) {
		enemyLoc[0] = Game::player->getLocation('x');
		enemyLoc[1] = Game::player->getLocation('y');
		if (playerLoc[0] == enemyLoc[0] + 1 && playerLoc[1] == enemyLoc[1]) {
			Game::player->setAlive(false);
			return (false);
		}
	}
	return (true);
}*/