#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

#include "./grid.cpp"


int main(int argc, char** argv) {
    srand(time(NULL));

    Grid grid;
    grid.init_ships();

    return 0;
}
