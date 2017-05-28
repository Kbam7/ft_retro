#include "GameClass.hpp"
#include <unistd.h>
#include <cstdlib>

Game::Game() {
	Game::enemies = new Player[5];
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	nodelay(stdscr, true);
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	int maxX, maxY;
	maxX = 0;
	maxY = 0;

	getmaxyx(stdscr, maxX, maxY);

	Game::gameWin = newwin(maxY,maxX,0,0);
	Game::player = new Player();
	//Game::HUDWin = newwin();
	//Game::gameWin = newwin();
	noecho();
	cbreak();
	nodelay(Game::gameWin, true);
	cbreak();
	nonl();
	intrflush(gameWin, FALSE);
	keypad(gameWin, TRUE);
	box(gameWin,0,0);
	move(2,2);
	wrefresh(gameWin);
	int x = 1;
	int y = 10;

	for (;;) {
		mvwprintw(gameWin, x, y, " ");
		int c = wgetch(gameWin);
		if (c == 'q' || c == 27)
			exit(0);
		else if (c == 'w' || c == KEY_UP)
			player->mvup();
		else if (c == 's' || c == KEY_DOWN)
			player->mvdown();
		else if (c == 'd' || c == KEY_RIGHT)
			player->mvright();
		else if (c == 'a' || c == KEY_LEFT)
			player->mvleft();
		if (Game::objectsCollide())
			break;
		updateDisplay();
		wrefresh(gameWin);
		napms(1000 / 60);
	}
}

void	Game::updateDisplay(void) {
	for (int i = 0 ;i < 5; i++) {
		if (Game::enemies[i].isAlive())
			Game::enemies[i].displayGameObject();
	}
}

bool	Game::objectsCollide(void) {
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
}

Game::~Game() {
	nodelay(Game::gameWin, FALSE);
	nodelay(stdscr, FALSE);
	getch();	// await input to kill
	endwin();	// ~destructor -> state teardown
}

