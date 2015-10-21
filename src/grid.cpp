#ifndef GRID_CPP
#define GRID_CPP

#include "./grid.h"
#include "./utils.h"


Grid::Grid(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}

void Grid::clear(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}
char Grid::get(int column, int row) {
    return grid[clamp_int(column - 1, 0, GRID_SIZE - 1)][clamp_int(row - 1, 0, GRID_SIZE - 1)];
}

bool Grid::is_hit(int column, int row) {
    return get(column, row) != '-';
}

void Grid::set(int column, int row, char value) {
    int c = clamp_int(column - 1, 0, GRID_SIZE - 1);
    int r = clamp_int(row - 1, 0, GRID_SIZE - 1);
    grid[c][r] = value;
}

void Grid::init_ships(void) {
    init_ship(AIRCRAFT_CARRIER_CODE, AIRCRAFT_CARRIER_LENGTH);

    init_ship(BATTLESHIP_CODE, BATTLESHIP_LENGTH);

    init_ship(CRUISER_CODE, CRUISER_LENGTH);
    init_ship(CRUISER_CODE, CRUISER_LENGTH);

    init_ship(SUBMARINE_CODE, SUBMARINE_LENGTH);
    init_ship(SUBMARINE_CODE, SUBMARINE_LENGTH);

    init_ship(PATROL_BOAT_CODE, PATROL_BOAT_LENGTH);
    init_ship(PATROL_BOAT_CODE, PATROL_BOAT_LENGTH);
    init_ship(PATROL_BOAT_CODE, PATROL_BOAT_LENGTH);
}

void Grid::init_ship(char code, int length) {
    bool orientation = rand() % 2 == 0; // 0 up/down, 1 left/right

    while (true) {
        int column = rand() % GRID_SIZE;
        int row = rand() % GRID_SIZE;

        if (check_row(code, length, column, row, orientation)) {
            add_ship(code, length, column, row, orientation);
            break;
        }
    }
}

bool Grid::check_row(char code, int length, int column, int row, bool orientation) {
	if (orientation) { // up/down
		if (column + length >= GRID_SIZE) {
			return false;
		} else {
			for (int i = 0; i < length; i++) {
				if (grid[column + i][row] != '-') {
					return false;
				}
			}
			return true;
		}
	} else { // left/right
		if (row + length >= GRID_SIZE) {
			return false;
		} else {
			for (int i = 0; i < length; i++) {
				if (grid[column][row + i] != '-') {
					return false;
				}
			}
			return true;
		}
	}
}

void Grid::add_ship(char code, int length, int column, int row, bool orientation) {
	if (orientation) { // up/down
		for (int i = 0; i < length; i++) {
			grid[column + i][row] = code;
		}
	} else { // left/right
		for (int i = 0; i < length; i++) {
			grid[column][row + i] = code;
		}
	}
}

void Grid::print(string name) {
	int size = 10; // name offset size

	cout << name << '\n';

	cout << setw(size);
	cout << ' ';
	for (int i = 0; i < GRID_SIZE; i++) {
            cout << ' ' << i + 1 << ' ';
    }
    cout << '\n';

	for (int i = 0; i < GRID_SIZE; i++) {
		cout << setw(size);
		cout << char(i + 'A');
        for (int j = 0; j < GRID_SIZE; j++) {
        	char ch = grid[i][j];

        	if (ch != '-' && ch != '/' && ch != 'X') {
        		cout << '[' << ch << ']';
			} else {
        		cout << ' ' << ch << ' ';
			}
        }
        cout << '\n';
    }
}

#endif
