#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#ifndef WIN32
    #define CLEAR "clear"
    //system("clear") pour UNIX
#else
    #define CLEAR "cls"
    //system("cls") pour Windows
#endif // WIN32

#define MINCHOIX 1
#define MAXCHOIX 4

enum{VIDE, JOUER, SCORES, QUITTER, JOUERSOLO, JOUERDUO, MENUP};

void viderBuffer();

#endif // CONSTANTES_H_INCLUDED
