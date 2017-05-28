#include "Player.hpp"
#include "GameObject.hpp"
#include <ncurses.h>

class Game {
	public:
		Game();
		~Game();
		Game(const Game&);
		Game	&operator=(const Game);
		void	updateDisplay(void);
		bool	objectsCollide(void);
	private:
	WINDOW	*menuWin;
	WINDOW	*HUDwin;
	WINDOW	*gameWin;
	Player	*player;
	Player	*enemies;
};

