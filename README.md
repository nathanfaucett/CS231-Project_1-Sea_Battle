CS231 Project #1: Sea Battle!
#####

For your first project, you will be using everything we have discussed so far about programming in C++ to implement a game called Sea Battle.  This is a two-player version of the popular strategy game, Battleship.

This game is played on four 10x10 grids.  Each player is assigned: a primary grid, a tracking grid, and a fleet of nine ships, deployed at random within their respective primary grids.  Depending on their size, the ships occupy two to five squares each, and they must be deployed in such a way that all of the ships fit within the bounds of the grid without overlapping (that is, without extending below the last row of the grid or "wrapping" from the right side of one row to the left side of the following row).  The players take turns firing shots at target squares within their opponent's primary grid, one shot per turn, recording hits and misses within their respective tracking grids.  The object of the game is to sink every ship in the opponent's fleet; to sink a ship, it is necessary to hit every square it occupies.  The first player to sink every ship in their opponent's fleet is the winner.

At the start of a game, both players launch the Sea Battle program on their own workstations, so that neither player can see their opponent's screen.  One of the two players specifies that they will be the one to take the first turn.  The program then creates a primary grid and tracking grid for each player, randomly populates the primary grid with a fleet of ships, and prints the contents of both grids to the screen.  The attacking player is asked to select a target square, which they then announce to the opponent.  The coordinates are entered by both players; the target square is then marked on the tracking grid of the attacking player, and on the primary grid of the opponent.  The opponent announces to the attacking player whether the shot was a "miss" (the target square was not occupied by any ship), a "hit" (the target square was occupied by a ship), or a "sink" (the target square was occupied by the last remaining square of a ship).  Both players enter this information at their workstations so that their fleet counts are kept up to date.  The players then reverse roles on the next turn, and continue taking shots until all of the ships in one player's fleet have been sunk.

The complement of ships in each player's fleet is as follows:

Quantity	Ship Type	Squares	Code
1	Aircraft Carrier	5	A
1	Battleship	4	B
2	Cruiser	3	C
2	Submarine	3	S
3	Patrol Boat	2	P

The squares occupied by each ship are indicated by their respective letter codes within the primary grid.  As the players take their shots, the target squares are marked with a "/" (a "splash mark") if the shot was a miss, or an "X" (a "bang mark") if the shot resulted in a hit or a sink.  See the example shown below, which depicts the output from the first few turns of a typical game.  The player's input is shown in bold.

```bash
Welcome to SEA BATTLE!

Will you take the first turn (Y/N)? y

PRIMARY       1  2  3  4  5  6  7  8  9  10
           A [P] -  -  - [B] -  -  -  -  -
           B [P] -  -  - [B] -  -  -  -  -
           C  -  - [P][P][B] -  -  -  -  -
           D  -  -  -  - [B] -  -  -  -  -
           E [A] -  -  - [C] -  -  -  -  -
           F [A][S] -  - [C] -  -  -  -  -
           G [A][S] -  - [C] - [C][C][C][S]
           H [A][S] -  -  -  -  -  -  - [S]
           I [A] -  -  -  -  -  -  -  - [S]
           J [P][P] -  -  -  -  -  -  -  -
TRACKING      1  2  3  4  5  6  7  8  9  10
           A  -  -  -  -  -  -  -  -  -  -
           B  -  -  -  -  -  -  -  -  -  -
           C  -  -  -  -  -  -  -  -  -  -
           D  -  -  -  -  -  -  -  -  -  -
           E  -  -  -  -  -  -  -  -  -  -
           F  -  -  -  -  -  -  -  -  -  -
           G  -  -  -  -  -  -  -  -  -  -
           H  -  -  -  -  -  -  -  -  -  -
           I  -  -  -  -  -  -  -  -  -  -
           J  -  -  -  -  -  -  -  -  -  -
Player: 9, Opponent: 9.  Your Target? E5
Was this a (M)iss, a (H)it, or a (S)ink? h

PRIMARY       1  2  3  4  5  6  7  8  9  10
           A [P] -  -  - [B] -  -  -  -  -
           B [P] -  -  - [B] -  -  -  -  -
           C  -  - [P][P][B] -  -  -  -  -
           D  -  -  -  - [B] -  -  -  -  -
           E [A] -  -  - [C] -  -  -  -  -
           F [A][S] -  - [C] -  -  -  -  -
           G [A][S] -  - [C] - [C][C][C][S]
           H [A][S] -  -  -  -  -  -  - [S]
           I [A] -  -  -  -  -  -  -  - [S]
           J [P][P] -  -  -  -  -  -  -  -
TRACKING      1  2  3  4  5  6  7  8  9  10
           A  -  -  -  -  -  -  -  -  -  -
           B  -  -  -  -  -  -  -  -  -  -
           C  -  -  -  -  -  -  -  -  -  -
           D  -  -  -  -  -  -  -  -  -  -
           E  -  -  -  -  X  -  -  -  -  -
           F  -  -  -  -  -  -  -  -  -  -
           G  -  -  -  -  -  -  -  -  -  -
           H  -  -  -  -  -  -  -  -  -  -
           I  -  -  -  -  -  -  -  -  -  -
           J  -  -  -  -  -  -  -  -  -  -
Player: 9, Opponent: 9.  Opponent's Target? E6


PRIMARY       1  2  3  4  5  6  7  8  9  10
           A [P] -  -  - [B] -  -  -  -  -
           B [P] -  -  - [B] -  -  -  -  -
           C  -  - [P][P][B] -  -  -  -  -
           D  -  -  -  - [B] -  -  -  -  -
           E [A] -  -  - [C] /  -  -  -  -
           F [A][S] -  - [C] -  -  -  -  -
           G [A][S] -  - [C] - [C][C][C][S]
           H [A][S] -  -  -  -  -  -  - [S]
           I [A] -  -  -  -  -  -  -  - [S]
           J [P][P] -  -  -  -  -  -  -  -
TRACKING      1  2  3  4  5  6  7  8  9  10
           A  -  -  -  -  -  -  -  -  -  -
           B  -  -  -  -  -  -  -  -  -  -
           C  -  -  -  -  -  -  -  -  -  -
           D  -  -  -  -  -  -  -  -  -  -
           E  -  -  -  -  X  -  -  -  -  -
           F  -  -  -  -  -  -  -  -  -  -
           G  -  -  -  -  -  -  -  -  -  -
           H  -  -  -  -  -  -  -  -  -  -
           I  -  -  -  -  -  -  -  -  -  -
           J  -  -  -  -  -  -  -  -  -  -
Player: 9, Opponent: 9.  Your Target? E6
Was this a (M)iss, a (H)it, or a (S)ink? m

PRIMARY       1  2  3  4  5  6  7  8  9  10
           A [P] -  -  - [B] -  -  -  -  -
           B [P] -  -  - [B] -  -  -  -  -
           C  -  - [P][P][B] -  -  -  -  -
           D  -  -  -  - [B] -  -  -  -  -
           E [A] -  -  - [C] /  -  -  -  -
           F [A][S] -  - [C] -  -  -  -  -
           G [A][S] -  - [C] - [C][C][C][S]
           H [A][S] -  -  -  -  -  -  - [S]
           I [A] -  -  -  -  -  -  -  - [S]
           J [P][P] -  -  -  -  -  -  -  -
TRACKING      1  2  3  4  5  6  7  8  9  10
           A  -  -  -  -  -  -  -  -  -  -
           B  -  -  -  -  -  -  -  -  -  -
           C  -  -  -  -  -  -  -  -  -  -
           D  -  -  -  -  -  -  -  -  -  -
           E  -  -  -  -  X  /  -  -  -  -
           F  -  -  -  -  -  -  -  -  -  -
           G  -  -  -  -  -  -  -  -  -  -
           H  -  -  -  -  -  -  -  -  -  -
           I  -  -  -  -  -  -  -  -  -  -
           J  -  -  -  -  -  -  -  -  -  -
Player: 9, Opponent: 9.  Opponent's Target? E5
*    *    *    *    B    O    O    M    *    *    *    *
Your opponent scored a hit!  Did it sink a ship (Y/N)? N


PRIMARY       1  2  3  4  5  6  7  8  9  10
           A [P] -  -  - [B] -  -  -  -  -
           B [P] -  -  - [B] -  -  -  -  -
           C  -  - [P][P][B] -  -  -  -  -
           D  -  -  -  - [B] -  -  -  -  -
           E [A] -  -  -  X  /  -  -  -  -
           F [A][S] -  - [C] -  -  -  -  -
           G [A][S] -  - [C] - [C][C][C][S]
           H [A][S] -  -  -  -  -  -  - [S]
           I [A] -  -  -  -  -  -  -  - [S]
           J [P][P] -  -  -  -  -  -  -  -
TRACKING      1  2  3  4  5  6  7  8  9  10
           A  -  -  -  -  -  -  -  -  -  -
           B  -  -  -  -  -  -  -  -  -  -
           C  -  -  -  -  -  -  -  -  -  -
           D  -  -  -  -  -  -  -  -  -  -
           E  -  -  -  -  X  /  -  -  -  -
           F  -  -  -  -  -  -  -  -  -  -
           G  -  -  -  -  -  -  -  -  -  -
           H  -  -  -  -  -  -  -  -  -  -
           I  -  -  -  -  -  -  -  -  -  -
           J  -  -  -  -  -  -  -  -  -  -
Player: 9, Opponent: 9.  Your Target?
```

(The ship deployment shown here is random, of course, so your ships will be deployed differently.)

As you work through this assignment, you can test your program on your own by launching two instances of the program, one for each "player".  As you take turns for both players, I suggest alternating between minimizing and restoring the corresponding windows, so that only one is visible at a time.  Once your program is running, you can use our weekly lab meetings to pair up with a classmate, so that the two of you can test your own versions of this program with a live human opponent.  You may even consider switching workstations, so that each player tries the other player's version of the program as they play through the game.

This assignment is worth 100 points and is due by the end of the day on Friday, November 6th.  When you have completed your program, submit your files to Blackboard in the form of a compressed archive containing your C++ program file and a compiled executable.  Refer to the "Frequently Asked Questions" folder, located under "Syllabus and Course Information" on Blackboard, for more information on how to submit files to Blackboard.
