#ifndef GRID_CPP
#define GRID_CPP

#include "./grid.h"
#include "./utils.h"


Grid::Grid(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            columns[i][j] = '-';
        }
    }
}

char Grid::get_index(int c, int r) {
    return columns[clamp_int(c, 0, GRID_SIZE - 1)][clamp_int(r, 0, GRID_SIZE - 1)];
}

char Grid::get(int column, char row_char) {
    return get_index(column - 1, (toupper(row_char) - 'A'));
}

void Grid::init_ships(void) {
    init_ship(AIRCRAFT_CARRIER_CODE, AIRCRAFT_CARRIER_LENGTH);
    //init_ship(BATTLESHIP_CODE, BATTLESHIP_LENGTH);
    //init_ship(CRUISER_CODE, CRUISER_LENGTH);
    //init_ship(SUBMARINE_CODE, SUBMARINE_LENGTH);
    //init_ship(PATROL_BOAT_CODE, PATROL_BOAT_LENGTH);
}

void Grid::init_ship(char code, int length) {
    bool done = false;
    int orientation = rand() % 2; // 0 up/down 1 left/right

    while (done == false) {
        int column = rand() % GRID_SIZE;
        int row = rand() % GRID_SIZE;

        if (check_row(code, length, column, row, orientation)) {
            add_ship(code, length, column, row, orientation);
            done = true;
        }
    }
}

bool Grid::check_row(char code, int length, int column, int row, int orientation) {
    return true;
}

void Grid::add_ship(char code, int length, int column, int row, int orientation) {

}


#endif
