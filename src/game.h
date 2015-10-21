#ifndef GAME_H
#define GAME_H

#include "./grid.h"


struct Game {
	bool your_turn;
	Grid tracking;
	Grid primary;

	int player;
	int opponent;

    Game(void);

    void init(void);
    void loop(void);
};

void get_input(int& column, int& row);

#endif
