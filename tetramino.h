struct quadratino{
    unsigned char y;
    unsigned char x;
};

class Tetramino{
public:
    //ogni tetramino è composto da quattro [] che hanno coordinate definite nello struct
    quadratino tetramino[4];

    WINDOW * curwin;

    //xloc e yloc coordinate attuali, xmax e ymax le coordinate massime che si possono assumere. altezza e larghezza sono le "misure"
    //del tetramino. moveR, moveL, e moveD sono flag che bloccano o meno il movimento a destra, sinistra o verso il basso
    int xloc, yloc, xmax, ymax;
    int altezza, larghezza;
    bool moveR, moveL, moveD;

    //costruttore dell'oggetto Tetramino
    Tetramino();

    //setta la finestra di gioco e le coordinate iniziali del tetramino
    void setwindow(WINDOW *, int, int);

    //permette il movimento verso il basso (controllando che non si sia arrivati in fondo)
    void mvdown();

    //permette il movimento verso sinistra (controllando di non andare oltre il bordo sinistro)
    void mvleft();

    //permette il movimento verso destra (controllando di non andare oltre il bordo destro)
    void mvright();

    //in seguito alla barra spaziatrice il tetramino viene spostato in fondo alla finestra di gioco
    void boom();

    //non usata?
    int getmv();
};


class Tet0 : public Tetramino{
public:
    //costruttore
    Tet0();

    //gestisce le rotazioni (le coordinate) del tetramino
    void rotazione(int);
};


class Tet1: public Tetramino{
public:
    //costruttore
    Tet1();
};


class Tet2: public Tetramino{
public:
    //costruttore
    Tet2();

    //gestisce le rotazioni (le coordinate) del tetramino
    void rotazione(int);
};


class Tet3 : public Tetramino{
public:
    //costruttore
    Tet3();

    //gestisce le rotazioni (le coordinate) del tetramino
    void rotazione(int);
};


class Tet4 : public Tetramino{
public:
    //costruttore
    Tet4();

    //gestisce le rotazioni (le coordinate) del tetramino
    void rotazione(int);
};


class Tet5 : public Tetramino{
public:
    //costruttore
    Tet5();

    //gestisce le rotazioni (le coordinate) del tetramino
    void rotazione(int);
};


class Tet6 : public Tetramino{
public:
    //costruttore
    Tet6();

    //gestisce le rotazioni (le coordinate) del tetramino
    void rotazione(int);
};

