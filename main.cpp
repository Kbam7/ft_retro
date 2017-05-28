/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:40:48 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 10:39:30 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

void game_clock(WINDOW * infowin)
{
	static time_t	clock_start = 0;
	time_t			result = 0;
	static long int	i;

	result = time(NULL);
	if (clock_start == 0)
		clock_start = result;
	else
	{
		i = result - clock_start;
		mvwprintw(infowin, 1, 12, "%li", i);
	}
}

int	main()
{
	initscr();
	noecho();
	cbreak();								// raw();
	curs_set(0);
	nodelay(stdscr, true);

	// get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	if (xMax < 50 || yMax < 20)
	{
		printw("Window too small\n");
		getch();
		return (0);
	}
	if (xMax > 150)
		xMax = 150;
	if (yMax > 50)
		yMax = 50;
	

	std::string	choices[2] = {"play", "exit"};
	int			choice;
	int			highlight = 0;
	int			new_y;
	int			new_x;

	while (1)
	{

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

				refresh();

				Player * p = new Player(gamewin, yMax);
				do {
					p->displayPlayer();
					mvwprintw(infowin, 1, 1, "Game Time: ");
					mvwprintw(infowin, 2, 1, "Score: ");
					mvwprintw(infowin, 3, 1, "Lives: ");
					game_clock(infowin);
					wrefresh(infowin);
					wrefresh(gamewin);

					getmaxyx(stdscr, new_y, new_x);
					if (new_y != yMax || new_x != xMax)
					{
						xMax = new_x;
						yMax = new_y;
						wresize(gamewin, new_y - 5, new_x);
						wresize(infowin, 5, new_x);
						mvwin(infowin, new_y - 5, 0);
						wclear(stdscr);
						wclear(gamewin);
						wclear(infowin);
						
				delwin(gamewin);
				delwin(infowin);
				
						WINDOW * infowin = newwin(5, xMax, 0, 0);
						box(infowin, 0, 0);
						wrefresh(infowin);

						WINDOW * gamewin = newwin(yMax - 5, xMax, 5, 0);
						box(gamewin, 0, 0);
						nodelay(gamewin, true);
						wrefresh(gamewin);
				
					}

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
