// Created by Beatrice on 01/03/2024.
#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H
#include <curses.h>
#include "tetramino.h"

Tetramino::Tetramino(){
    moveR = true;
    moveL = true;
    moveD = true;
}
void Tetramino::setwindow(WINDOW * win, int y, int x){
    this->curwin = win;
    this->yloc = y;
    this->xloc = x;
    getmaxyx(curwin, ymax, xmax);
    keypad(curwin, true);
}

void Tetramino::mvdown(){
    if((yloc+altezza) == ymax-1)
        moveD = false;
    if(moveD)
        yloc++;
}

void Tetramino::mvleft(){
    if(xloc == 1)
        moveL = false;
    if(moveL && moveD)
        xloc--;
    moveR = true;
}

void Tetramino::mvright(){
    if((xloc+larghezza) == xmax/2 -1)
        moveR = false;
    if(moveR && moveD)
        xloc++;
    moveL = true;
}

void Tetramino::boom(){
    yloc = ymax-altezza-1;
    moveD = false;
}

int Tetramino::getmv() {
    int choice = -1;
    if (wgetch(curwin) == KEY_DOWN)
        mvdown();
    else if (wgetch(curwin) == KEY_LEFT)
        mvleft();
    else if(wgetch(curwin) == KEY_RIGHT)
        mvright();
    else if(wgetch(curwin) == 32)
        boom();
    return choice;
}



Tet0::Tet0(){
    this->tetramino[0].x = 6;           //[]
    this->tetramino[0].y = 0;           //[]
                                        //[]
    this->tetramino[1].x = 6;           //[]
    this->tetramino[1].y = 1;

    this->tetramino[2].x = 6;
    this->tetramino[2].y = 2;

    this->tetramino[3].x = 6;
    this->tetramino[3].y = 3;

    larghezza = 1;
    altezza = 4;
}

void Tet0::rotazione(int r){
    if(r == 1 || r == 3 ){
        this->tetramino[0].y = 0;   //[][][][]
        this->tetramino[0].x = 0;
        this->tetramino[1].y = 0;
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 0;
        this->tetramino[2].x = 2;
        this->tetramino[3].y = 0;
        this->tetramino[3].x = 3;

        this->altezza = 1;
        this->larghezza = 4;
    }
    if(r == 2){
        this->tetramino[0].y = 0;
        this->tetramino[0].x = 0;
        this->tetramino[1].y = 1;
        this->tetramino[1].x = 0;
        this->tetramino[2].y = 2;
        this->tetramino[2].x = 0;
        this->tetramino[3].y = 3;
        this->tetramino[3].x = 0;
    }
}


Tet1::Tet1(){
    this->tetramino[0].x = 6;           //[][]
    this->tetramino[0].y = 0;           //[][]

    this->tetramino[1].x = 6;
    this->tetramino[1].y = 1;

    this->tetramino[2].x = 7;
    this->tetramino[2].y = 0;

    this->tetramino[3].x = 7;
    this->tetramino[3].y = 1;

    larghezza = 2;
    altezza = 2;

}



Tet2::Tet2(){
    this->tetramino[0].x = 5;           //[][][]
    this->tetramino[0].y = 0;           //    []

    this->tetramino[1].x = 6;
    this->tetramino[1].y = 0;

    this->tetramino[2].x = 7;
    this->tetramino[2].y = 0;

    this->tetramino[3].x = 7;
    this->tetramino[3].y = 1;

    larghezza = 3;
    altezza = 2;
}

void Tet2::rotazione(int r){
    if(r == 1){
        this->tetramino[0].y = 0;       //  []
        this->tetramino[0].x = 1;       //  []
        this->tetramino[1].y = 1;       //[][]
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 2;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 0;

        this->altezza = 3;
        this->larghezza = 2;
    }
    if(r == 2){
        this->tetramino[0].y = 0;       //[]
        this->tetramino[0].x = 0;       //[][][]
        this->tetramino[1].y = 1;
        this->tetramino[1].x = 0;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 1;
        this->tetramino[3].x = 2;

        this->altezza = 2;
        this->larghezza = 3;
    }
    if(r == 3){
        this->tetramino[0].y = 0;       //[][]
        this->tetramino[0].x = 0;       //[]
        this->tetramino[1].y = 0;       //[]
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 0;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 0;

        this->altezza = 3;
        this->larghezza = 2;
    }

}

Tet3::Tet3(){
    this->tetramino[0].x = 5;           //[][][]
    this->tetramino[0].y = 0;           //[]

    this->tetramino[1].x = 6;
    this->tetramino[1].y = 0;

    this->tetramino[2].x = 7;
    this->tetramino[2].y = 0;

    this->tetramino[3].x = 5;
    this->tetramino[3].y = 1;
    larghezza = 3;
    altezza = 2;
}

void Tet3::rotazione(int r) {
    if(r == 1){
        this->tetramino[0].y = 0;       //[][]
        this->tetramino[0].x = 0;       //  []
        this->tetramino[1].y = 0;       //  []
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 1;

        this->altezza = 3;
        this->larghezza = 2;
    }
    if(r == 2){
        this->tetramino[0].y = 0;       //    []
        this->tetramino[0].x = 2;       //[][][]
        this->tetramino[1].y = 1;
        this->tetramino[1].x = 0;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 1;
        this->tetramino[3].x = 2;

        this->altezza = 2;
        this->larghezza = 3;
    }
    if(r == 3){
        this->tetramino[0].y = 0;       //[]
        this->tetramino[0].x = 0;       //[]
        this->tetramino[1].y = 1;       //[][]
        this->tetramino[1].x = 0;
        this->tetramino[2].y = 2;
        this->tetramino[2].x = 0;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 1;

        this->altezza = 3;
        this->larghezza = 2;
    }
}


Tet4::Tet4(){
    this->tetramino[0].x = 5;           //[][]
    this->tetramino[0].y = 0;           //  [][]

    this->tetramino[1].x = 6;
    this->tetramino[1].y = 0;

    this->tetramino[2].x = 6;
    this->tetramino[2].y = 1;

    this->tetramino[3].x = 7;
    this->tetramino[3].y = 1;
    larghezza = 3;
    altezza = 2;
}

void Tet4::rotazione(int r) {
    if (r == 1 || r == 3) {
        this->tetramino[0].y = 0;       //  []
        this->tetramino[0].x = 1;       //[][]
        this->tetramino[1].y = 1;       //[]
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 0;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 0;
    }

    this->altezza = 3;
    this->larghezza = 2;
}


Tet5::Tet5(){
    this->tetramino[0].x = 6;           //  [][]
    this->tetramino[0].y = 0;           //[][]

    this->tetramino[1].x = 7;
    this->tetramino[1].y = 0;

    this->tetramino[2].x = 5;
    this->tetramino[2].y = 1;

    this->tetramino[3].x = 6;
    this->tetramino[3].y = 1;
    larghezza = 3;
    altezza = 2;
}

void Tet5::rotazione(int r) {
    if (r == 1 || r == 3) {
        this->tetramino[0].y = 0;       //[]
        this->tetramino[0].x = 0;       //[][]
        this->tetramino[1].y = 1;       //  []
        this->tetramino[1].x = 0;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 1;

        this->altezza = 3;
        this->larghezza = 2;
    }
}


Tet6::Tet6(){
    this->tetramino[0].x = 6;           //  []
    this->tetramino[0].y = 0;           //[][][]

    this->tetramino[1].x = 5;
    this->tetramino[1].y = 1;

    this->tetramino[2].x = 6;
    this->tetramino[2].y = 1;

    this->tetramino[3].x = 7;
    this->tetramino[3].y = 1;
    larghezza = 3;
    altezza = 2;
}

void Tet6::rotazione(int r){
    if(r == 1){
        this->tetramino[0].y = 0;       //[]
        this->tetramino[0].x = 0;       //[][]
        this->tetramino[1].y = 1;       //[]
        this->tetramino[1].x = 0;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 0;

        this->altezza = 3;
        this->larghezza = 2;
    }
    if(r == 2){
        this->tetramino[0].y = 0;       //[][][]
        this->tetramino[0].x = 0;       //  []
        this->tetramino[1].y = 0;
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 0;
        this->tetramino[2].x = 2;
        this->tetramino[3].y = 1;
        this->tetramino[3].x = 1;

        this->altezza = 2;
        this->larghezza = 3;
    }
    if(r == 3){
        this->tetramino[0].y = 1;       //  []
        this->tetramino[0].x = 0;       //[][]
        this->tetramino[1].y = 0;       //  []
        this->tetramino[1].x = 1;
        this->tetramino[2].y = 1;
        this->tetramino[2].x = 1;
        this->tetramino[3].y = 2;
        this->tetramino[3].x = 1;

        this->altezza = 3;
        this->larghezza = 2;
    }
}

#endif //TETRIS_TETRAMINO_H