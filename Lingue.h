#ifndef TETRIS_LINGUE_H
#define TETRIS_LINGUE_H

#include <iostream>
#include <cstring>
using namespace std;

//struttura lingua identificata da id e contenente array con parole della lingua
struct lingue{
    int id;
    string parole[7];
    lingue *next;
};
typedef lingue* pLingue;

//Inserimento in testa della lista
pLingue headInsert(pLingue, string[], int, int );

//Sposta un nodo in testa (la lingua in testa è quella selezionata dall'utente)
pLingue scambiaNodi(pLingue, int);

//Restituisce la testa della lista delle lingue
pLingue getLingue(pLingue);

#endif