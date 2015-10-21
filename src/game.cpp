#ifndef GAME_CPP
#define GAME_CPP

#include "./game.h"
#include "./grid.cpp"

#define SHIP_COUNT 9;


Game::Game(void) {
	cout << "\nWelcome to SEA BATTLE!\n\n";
	init();
}

void Game::init(void) {
	player = SHIP_COUNT;
	opponent = SHIP_COUNT;

	tracking.clear();
	primary.clear();

	primary.init_ships();

	cout << "Will you take the first turn (Y/N)? ";
	char value;
	cin >> value;
	cout << '\n';

	if (toupper(value) == 'Y') {
		your_turn = true;
	} else {
		your_turn = false;
	}

	loop();
}

void Game::loop(void) {
	int column, row;
	char value;

	primary.print("PRIMARY");
	tracking.print("TRACKING");

	if (your_turn) {
		cout << "Player: " << player << ", Opponent: " << opponent << ".  Your Target? ";
		get_input(column, row);

		cout << "Was this a (M)iss, a (H)it, or a (S)ink? ";
		cout << '\n';

		while (true) {
			cin >> value;
			value = toupper(value);

			if (value == 'M') {
				tracking.set(column, row, '/');
				break;
			} else if (value == 'H') {
				tracking.set(column, row, 'X');
				break;
			} else if (value == 'S') {
				tracking.set(column, row, 'X');
				opponent -= 1;
				break;
			} else {
				cout << "Invalid input please input (M)iss, a (H)it, or a (S)ink? ";
			}
		}
	} else {
		cout << "Player: " << player << ", Opponent: " << opponent << ".  Opponent's Target? ";
		get_input(column, row);

		if (primary.is_hit(column, row)) {
			primary.set(column, row, 'X');

			cout << "*    *    *    *    B    O    O    M    *    *    *    *\n";
			cout << "Your opponent scored a hit!  Did it sink a ship (Y/N)? ";
			cin >> value;
			cout << '\n';

			if (toupper(value) == 'Y') {
				player -= 1;
			}
		} else {
			primary.set(column, row, '/');
		}
	}

	if (player <= 0) {
		cout << "You lost the Game. Play Again (Y/N)?\n";

		char play_again;
		cin >> play_again;
		cout << '\n';
		if (toupper(play_again) == 'Y') {
			init();
		}
	} else if (opponent <= 0) {
		cout << "You won the Game!! Play Again (Y/N)?\n";

		char play_again;
		cin >> play_again;
		cout << '\n';
		if (toupper(play_again) == 'Y') {
			init();
		}
	} else {
		your_turn = !your_turn;
		loop();
	}
}

void get_input(int& column, int& row) {
	string input;

	while (true) {
		cin >> input;

		char c = toupper(input[0]);
		int r;

		if (input.size() == 2) {
			r = input[1] - '0';
		} else if (input.size() == 3 && input[1] == '1' && input[2] == '0') {
			r = 10;
		} else {
			cout << "Invalid input please input row and column within grid, example E5? ";
			continue;
		}

		if (
			(c >= 'A' && c <= ('A' + GRID_SIZE)) &&
			r > 0 && r <= GRID_SIZE
		) {
			column = (c - 'A') + 1;
			row = r;
			break;
		} else {
			cout << "Invalid input please input row and column within grid, example E5? ";
		}
	}
}


#endif
