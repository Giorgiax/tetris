
#include <iostream>
#include <ncurses.h>
#include <string>
#include "Gioco.h"
#include <stdlib.h>
#include <ctime>
#include "Lingue.h"

const int Height = 25;
const int Width = 32;
const int StartY = 5;
const int StartX = 65;


int aligned(WINDOW *win, string s){
    int y, x, start;
    getmaxyx(win, y, x);
    start = (x - s.length())/2;

    return start;
}


int muovi(int tasto, int choice, int last){
    //  FRECCIA GIU
    if(tasto == KEY_DOWN) {
        if(choice != last) {
            choice++;
        }
        else{
            choice = 0;
        }
    }

    // FRECCIA SU
    if(tasto == KEY_UP) {
        if(choice != 0) {
            choice--;
        }
        else{
            choice = last;
        }
    }
    return choice;
}


int languages(){
    //creazione e inizializzazione della finestra
    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    WINDOW * languages = newwin(Height, Width, StartY, StartX);
    wrefresh(languages);
    box(languages, 0, 0);
    refresh();
    keypad(languages, true);


    string lingue[5] = {"ITALIANO", "ENGLISH", "ESPANOL", "FRANCAIS" , "RUSSO"};
    int tasto;
    int choice = 0;

    while (1){
        for (int i = 0; i < 5; ++i) {
            if(i == choice){
                wattron(languages, A_REVERSE);
            }
            int startx = aligned(languages, lingue[i].c_str());
            mvwprintw(languages, 2 * i + 7, startx, lingue[i].c_str());
            wattroff(languages, A_REVERSE);
        }

        tasto = wgetch(languages);
        choice = muovi(tasto, choice, 4);


        // IN QUALE LINGUA CAMBIO
        if(tasto == 10){
            if (choice == 0){
                return 0;
            }
            if (choice == 1){
                return 1;
            }
            if (choice == 2){
                return 2;
            }
            if (choice == 3){
                return 3;
            }if (choice == 4){
                return 4;
            }
        }
    }
}


int settings(pLingue head){
    //creazione e inizializzazione della finestra
    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    WINDOW *settings = newwin(Height, Width, StartY, StartX);
    wrefresh(settings);
    box(settings, 0, 0);
    refresh();
    keypad(settings, true);


    string scelta[4] = {head->parole[5], head->parole[6],  "<--"};
    int tasto;
    int choice = 0;
    int linguaAtt;
    mvwprintw(settings, 1, 2, head->parole[3].c_str());

    while (1){
        for(int i = 0; i < 4; i++){
            int startx = aligned(settings, scelta[i].c_str());
            if(i == choice){
                wattron(settings, A_STANDOUT);
            }
            if(i == 2){
                mvwprintw(settings, i+20, 23, scelta[i].c_str());
            }
            else {
                mvwprintw(settings, 2 * i + 7, startx, scelta[i].c_str());
            }
            wattroff(settings, A_STANDOUT);
        }

        tasto = wgetch(settings);
        choice = muovi(tasto, choice, 2);

        // INVIO

        if(tasto == 10){
            if(choice == 0){
                wclear(settings);
                linguaAtt = languages();
                mvwprintw(settings, 1, 2, "Menu:");
                box(settings, 0, 0);
                refresh();
                wrefresh(settings);
            }
            if(choice == 2){
                wclear(settings);
                wrefresh(settings);
                delwin(settings);
                break;
            }
            if(choice == 3) {

            }
            if(choice == 5){
                break;
            }
        }
        if(tasto == 27)      //ESC
            break;
    }
    return linguaAtt;
}

void menu(pLingue head){
    bool k = false;
    WINDOW *menu = newwin(Height, Width, StartY, StartX);
    refresh();

    box(menu, 0, 0);
    refresh();

    keypad(menu, true);

    int tasto;
    int choice = 0;
    int l = 0;
    int ls = 0;

    mvwprintw(menu, 1, 2, "Menu:");

    while (1){
        string scelta[5] = {head->parole[0], head->parole[1], head->parole[2], head->parole[3], head->parole[4], };
        for(int i = 0; i < 5; i++){
            if(i == choice){
                wattron(menu, A_REVERSE);
            }

            int startx = aligned(menu, scelta[i].c_str());
            if(i < 1) {
                mvwprintw(menu, 5, startx, scelta[i].c_str());
            }

            if(i == 1){
                mvwprintw(menu, 7, startx, scelta[i].c_str());
                mvwprintw(menu, 8, getmaxx(menu)/2 - 1, "%d", l);
                wrefresh(menu);
            }

            if(i > 1){
                mvwprintw(menu, 2 * i + 6, startx, scelta[i].c_str());
            }
            wattroff(menu, A_REVERSE);

        }

        tasto = wgetch(menu);
        choice = muovi(tasto, choice, 4);

        // SE TI TROVI SU "LEVEL"
        if(choice == 1){
            k = true;
        }
        else{
            k = false;
        }

        // DIMINUISCI IL LIVELLO
        if(tasto == KEY_LEFT && k){
            if(l > 0){
                l--;
            }
            else{
                l = 9;
            }
        }

        // AUMENTA LIVELLO
        if(tasto == KEY_RIGHT && k){
            if(l < 9){
                l++;
            }
            else{
                l = 0;
            }
        }

        // INVIO
        if(tasto == 10){
            if(choice == 0){
                int n = 1 + rand()%7;
                play(0);
            }
            else if(choice == 2){

            }
            else if(choice == 3){
                int linguaAtt = settings(head);
                head = scambiaNodi(head, linguaAtt);
                refresh();
                wrefresh(menu);
            }
            else if(choice == 4){
                break;
            }
        }
        if(tasto == 27) {     //ESC
            break;
        }
    }
}


