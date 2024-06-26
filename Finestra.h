#ifndef TETRIS_FINESTRA_H
#define TETRIS_FINESTRA_H
#include <iostream>
#include <ncurses.h>
#include <string>
#include "Gioco.h"
#include <stdlib.h>
#include <ctime>
#include "Lingue.h"

//funzione che allinea il testo al centro della finestra
int aligned(WINDOW *, string);

//funzione che gestisce l'input da tastiera (frecce)
int muovi(int, int, int);

//funziona che gestisce la finstra LINGUE a cui si accede via menu
int languages();

//funzione che gestisce la finestra IMPOSTAZIONI a cui si accede via menu
int settings(pLingue);

void menu(pLingue);

#endif