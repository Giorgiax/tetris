
#ifndef TETRIS_GIOCO_H
#define TETRIS_GIOCO_H
#include <stdlib.h>
#include <ctime>
#include <curses.h>
#include "tetramino.h"
#include <unistd.h>

//inizializza i colori
void initialize_colours();

//"disegna" il tetramino
void draw(WINDOW *, Tetramino *, int, int, int);

//muove il tetramino
void move(Tetramino *, int, WINDOW *, int);

//crea il tetramino del tipo int in input (random da 0 a 6)
Tetramino * creaTet(int);

//Gioco
void play(int);

#endif