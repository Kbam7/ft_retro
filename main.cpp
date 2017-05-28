/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:40:48 by dmather           #+#    #+#             */
/*   Updated: 2017/05/28 07:55:19 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Player.hpp"
#include "Entity.hpp"

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
	if (xMax < 50)
		xMax = 50;
	if (yMax < 20)
		yMax = 20;
	if (xMax > 150)
		xMax = 150;
	if (yMax > 50)
		yMax = 50;
	

	std::string	choices[2] = {"play", "exit"};
	int			choice;
	int			highlight = 0;

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

				Player * p = new Player(gamewin);
				Entity * e = new Entity(20);

				do {
					p->displayGameObject();
					wrefresh(gamewin);
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
