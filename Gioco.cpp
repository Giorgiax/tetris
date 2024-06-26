#include "Gioco.h"
#include <stdlib.h>
#include <ctime>
#include <curses.h>
#include <unistd.h>

const int height = 25;
const int width = 32;
const int start_y = 5;
const int start_x = 65;


void initialize_colours(){
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_CYAN);
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    init_pair(5, COLOR_RED, COLOR_RED);
    init_pair(6, COLOR_GREEN, COLOR_GREEN);
    init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
}

void draw(WINDOW *win, Tetramino *t, int type, int yloc, int xloc){
    werase(win);
    for (int i = 0; i < 4; i++) {
        int x = t->tetramino[i].x;
        int y = t->tetramino[i].y;
        wattron(win, COLOR_PAIR(type+1));
        mvwprintw(win, yloc + y, 2*(xloc + x), "[]");
        wattroff(win, COLOR_PAIR(type+1));
    }
}

void move(Tetramino *tet, int t, WINDOW *playwin, int wasd) {
    while(tet->moveD){
        draw(playwin, tet, t, tet->yloc, tet->xloc);
        box(playwin, 0, 0);
        wrefresh(playwin);
        usleep(500000);                                     //cambiare con var per liv
        nodelay(playwin, true);

        int choice = wgetch(playwin);
        if(choice == ERR){
            tet->mvdown();
            draw(playwin, tet, t, tet->yloc, tet->xloc);
            box(playwin, 0, 0);
            wrefresh(playwin);
        }else{
            if (wasd == 0) {                                               //i tasti per il movimento dei tetramini da freccette a WASD
                if (choice == KEY_DOWN) {
                    tet->mvdown();
                } else if (choice == KEY_LEFT) {
                    tet->mvleft();
                } else if (choice == KEY_RIGHT) {
                    tet->mvright();
                }
                else if(choice == 32){
                    tet->boom();
                }
                else {
                    tet->mvdown();
                    draw(playwin, tet, t, tet->yloc, tet->xloc);
                    box(playwin, 0, 0);
                    wrefresh(playwin);
                }
            }
            else {
                if (choice == 83 || choice == 119) {
                    tet->mvdown();
                } else if (choice == 97 || choice == 65) {
                    tet->mvleft();
                } else if (choice == 68 || choice == 100) {
                    tet->mvright();
                }
                else if(choice == 32){
                    tet->boom();
                }
                else {
                    tet->mvdown();
                    draw(playwin, tet, t, tet->yloc, tet->xloc);
                    box(playwin, 0, 0);
                    wrefresh(playwin);
                }
            }
        }
    }
}

Tetramino* creaTet(int t){
    Tetramino *tet;
    if(t == 0){
        tet = new Tet0();
    }
    if(t == 1){
        tet = new Tet1();
    }
    if(t == 2){
        tet = new Tet2();
    }
    if(t == 3){
        tet = new Tet3();
    }
    if(t == 4){
        tet = new Tet4();
    }
    if(t == 5){
        tet = new Tet5();
    }
    if(t == 6){
        tet = new Tet6();
    }

    return tet;
}

void addTet(WINDOW *playwin, int wasd, bool primo = false){
    int t = rand() % 7;
    Tetramino *tet = creaTet(t);
    if(primo)
        tet->setwindow(playwin, 1, 1);
    else{
        tet->yloc = 1;
        tet->xloc = 1;
        getmaxyx(playwin, tet->ymax, tet->xmax);
    }
    move(tet, t, playwin, wasd);
}

void play(int wasd) {
    srand(time(0));
    initscr();
    noecho();
    curs_set(0);

    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW *playwin = newwin(height, width, start_y, start_x);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    initialize_colours();
    addTet(playwin, wasd, true);
    for(int i = 0; i < 3; i++){
        addTet(playwin, wasd);
    }

    endwin();
}

