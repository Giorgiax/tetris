#include <iostream>
#include <string>
#include "Lingue.h"
using namespace std;

pLingue headInsert(pLingue h, string a[], int l, int id){
    pLingue p = new lingue;
    p->id = id;
    for (int i = 0; i < l; ++i) {
        p->parole[i] = a[i];
    }
    p->next = h;

    return p;
}


pLingue scambiaNodi(pLingue h, int n){
    if(h->id == n){
        return h;
    }
    else{
        pLingue prev = NULL;
        pLingue tmp = h;

        while (tmp != NULL && tmp->id != n){
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = tmp->next;
        tmp->next = h;
        h = tmp;

        return h;
    }
}

pLingue getLingue(pLingue head){

    string italiano[7];
    italiano[0] = " NUOVA PARTITA ";
    italiano[1] = " < LIVELLO > ";
    italiano[2] = " CLASSIFICA ";
    italiano[3] = " IMPOSTAZIONI ";
    italiano[4] = " ESCI ";
    italiano[5] = " LINGUE ";
    italiano[6] = " CONTROLLI ";

    string inglese[7];
    inglese[0] = " NEW GAME ";
    inglese[1] = " < LEVEL > ";
    inglese[2] = " HIGH SCORES ";
    inglese[3] = " SETTINGS ";
    inglese[4] = " EXIT ";
    inglese[5] = " LANGUAGES ";
    inglese[6] = " CONTROLS ";

    string spagnolo[7];
    spagnolo[0] = " NUEVO PARTIDO ";
    spagnolo[1] = " < NIVEL > ";
    spagnolo[2] = " CLASIFICACION ";
    spagnolo[3] = " AJUSTES ";
    spagnolo[4] = " SALES ";
    spagnolo[5] = " IDIOMAS ";
    spagnolo[6] = " CONTROLS ";

    string francese[7];
    francese[0] = " NOUVEAU MATCH ";
    francese[1] = " < NIVEAU > ";
    francese[2] = " CLASSIFICATION ";
    francese[3] = " PARAMETRES ";
    francese[4] = " VOUS SORTEZ ";
    francese[5] = " LANGUES ";
    francese[6] = " CONTROLES ";

    string russo[7];
    russo[0] = " HOBbIN MaTY "; //новый матч
    russo[1] = " ypoBeHb ";
    russo[2] = " Klassifikatsiya ";
    russo[3] = " Hactponkn ";
    russo[4] = " BbIXOA ";
    russo[5] = " R3bIKN ";
    russo[6] = " nastroyki ";

    head = headInsert(head, inglese, 7, 1);
    head = headInsert(head, spagnolo, 7, 2);
    head = headInsert(head, francese, 7, 3);
    head = headInsert(head, russo, 7, 4);
    head = headInsert(head, italiano, 7, 0);

    return head;
}
