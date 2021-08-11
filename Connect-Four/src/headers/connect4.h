#ifndef CONNECT_4
#define CONNECT_4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 6
#define MAX_COL 7
#define HAS_SEEDED
typedef enum boolean
{
    NAY=0, YES=1
} Bool;

typedef enum occupied
{
	FALSE, TRUE
} Occupied;

typedef struct location
{
	int row;
	int col;
} Location;

typedef struct cell
{
	char color;
	Occupied isOccupied;
	Location place;
} Cell;

typedef struct player
{
    char color;
    int score;

} Player;


void init_board(Cell board[][MAX_COL], int rows, int cols);
Bool hasWon(Cell board[][MAX_COL], Player pp);
void drop_piece(Cell board[][MAX_COL], Player pp, int column);
void displayBoard(Cell board[][MAX_COL]);
int computer_player(Cell board[][MAX_COL]);
int game(Cell board[][MAX_COL], Player pp[], int *round);
int connect4_run();


#endif