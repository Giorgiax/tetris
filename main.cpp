#include <iostream>
#include <ncurses.h>
#include <string>
#include <stdlib.h>
#include <ctime>

#include "Gioco.h"
#include "Lingue.h"
#include "Finestra.h"
using namespace std;

const int Height = 25;
const int Width = 32;
const int StartY = 5;
const int StartX = 65;

int main(int argc, char *argv[]) {

    pLingue head = new lingue;
    head = getLingue(head);

    initscr(); //inizializzazione
    cbreak();
    noecho();
    start_color();
    curs_set(0);

    menu(head);


    endwin();

    return 0;
}
