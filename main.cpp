/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:40:48 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 18:23:36 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Player.hpp"
#include "BasicEnemy.hpp"
#include "Bullet.hpp"
#include <sys/time.h>

#define	MAX_ENEMY 10

bool	checkBulletCollision(Bullet *b, BasicEnemy *e);

static long int	sec;
static long int	microsec;

void game_clock(WINDOW * infowin)
{	
	struct timeval tv;
	static suseconds_t	clock_start = 0;

	if (gettimeofday(&tv, NULL) == 0)
	{
		if (clock_start == 0)
			clock_start = tv.tv_sec;
		else
		{
			sec = tv.tv_sec - clock_start;
			microsec = tv.tv_usec / 10000;
			mvwprintw(infowin, 1, 12, "%li", sec);
		}
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
				/*	if (p->getmv(microsec) == 32)
					{
						Bullet *b = new Bullet(p->getLocation('x'), p->getLocation('y')); //this->_currLocation[0], this->_currLocation[1]
					//	b->setLocation(p->getLocation('x'), p->getLocation('y'));
						mvwaddch(gamewin, b->_yLoc, ++b->_xLoc, '-');
						if (microsec)
						{}
					}*/

					for (int i = 0 ; i < MAX_ENEMY; i++) {
						if (e[i]->isAlive() && (sec - e[i]->_lastSpawnTime) == 1)
						{
							e[i]->_lastSpawnTime = sec;
							e[i]->mvleft();
							e[i]->displayGameObject();
			//		if (checkBulletCollision(b, e))
			//		{
			//			e[i]->setAlive(false);
			//		}
						}
						//--------------------------------------------------------------------
						/*if ((sec - e[i]->_lastSpawnTime) == 5)
						{
							e[i]->_lastSpawnTime = sec;
							BasicEnemy * n[MAX_ENEMY];
							srand(time(0));
							int y;
							for (int x = 0; x < MAX_ENEMY; ++x)
							{
								y = (rand() % yMax);
								if (y >= yMax - 1)
									y = yMax - 2;
								else if (y < 1)
									y = 1;

								n[x] = new BasicEnemy(gamewin, xMax - 2, y);

							}
						}*/
						//----------------------------------------------------------------
					}
					if (p->isAlive())
					{
						int	playerLoc[2], enemyLoc[2];
						
						playerLoc[0] = p->getLocation('x');
						playerLoc[1] = p->getLocation('y');
						for (int i = 0 ;i < MAX_ENEMY; i++) {
							enemyLoc[0] = e[i]->getLocation('x');
							enemyLoc[1] = e[i]->getLocation('y');
							if (playerLoc[1] == enemyLoc[1] && (playerLoc[0] == enemyLoc[0] - 1 || playerLoc[0] == enemyLoc[0]) ) {
								p->setAlive(false);
								break;
							}
						}
						if (p->isAlive())
							p->displayGameObject();
					}

					mvwprintw(infowin, 1, 1, "Game Time: ");
					mvwprintw(infowin, 2, 1, "Score: 0");
					mvwprintw(infowin, 3, 1, "Lives: 1");
					game_clock(infowin);
					wrefresh(infowin);
					wrefresh(gamewin);
					refresh();
				} while (p->getmv(microsec) != 27 && p->isAlive());
				//reset_all();

				delwin(gamewin);
				delwin(infowin);
				endwin();
				continue;
			}
		}
	}
	return (0);
}

bool	checkBulletCollision(Bullet *b, BasicEnemy *e) {
	int	bulletLoc[2], enemyLoc[2];

	bulletLoc[0] = b->getLocation('x');
	bulletLoc[1] = b->getLocation('y');
	// Check enemies
	for (int i = 0 ;i < MAX_ENEMY; i++) {
		enemyLoc[0] = e->getLocation('x');
		enemyLoc[1] = e->getLocation('y');
		if (bulletLoc[1] == enemyLoc[1] && (bulletLoc[0] == enemyLoc[0] + 1 || bulletLoc[0] == enemyLoc[0]) ) {
			e[i].setAlive(false);
			return (true);
		}
//	if (b->getLocation('x') > xMax - 2)
//		delete b;
	}
	return (false);
}
