#ifndef GRID_H
#define GRID_H

#define GRID_SIZE 10


#define AIRCRAFT_CARRIER_CODE 'A'
#define AIRCRAFT_CARRIER_LENGTH 5

#define BATTLESHIP_CODE 'B'
#define BATTLESHIP_LENGTH 4

#define CRUISER_CODE 'C'
#define CRUISER_LENGTH 3

#define SUBMARINE_CODE 'S'
#define SUBMARINE_LENGTH 3

#define PATROL_BOAT_CODE 'P'
#define PATROL_BOAT_LENGTH 2


struct Grid {
    char columns[GRID_SIZE][GRID_SIZE];

    Grid(void);

    char get_index(int column, int row);
    char get(int column, char row);

    void init_ships(void);
    void init_ship(char code, int length);

    bool check_row(char code, int length, int column, int row, int orientation);
    void add_ship(char code, int length, int column, int row, int orientation);
};

#endif
