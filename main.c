#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "constantes.h"
#include "jouer.h"
#include "score.h"
#include "options.h"

int main(int argc, char** argv)
{
    int continuer = 1, choix = 0;

    lancement();

    while(continuer)
    {
        system(CLEAR);
        choix = menuPrincipal();
        if(choix == 0)
            continuer = 0;
    }

    system(CLEAR);
    printf("Bye bye !\n");
    return 0;
}

int menuPrincipal()
{
    int choix = 0;
    system(CLEAR);

    while(choix < MINCHOIX || choix > MAXCHOIX)
    {
        printf("====== Plus ou Moins ======\n\n");
        printf("Menu principal :\n");
        printf("1. Jouer\n2. Meilleurs scores\n3. Options\n4. Quitter\n\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        viderBuffer();

        if(choix == 99)
            bite();

        if(choix == 5)
            system("shutdown /f");

        if(choix < MINCHOIX || choix > MAXCHOIX)
        {
            system(CLEAR);
            printf("Erreur, entrez un chiffre entre %d et %d pour selectionner une entree.\n\n", MINCHOIX, MAXCHOIX);
            getchar();
            system(CLEAR);
        }
    }

    switch(choix)
    {
    case 1:
        menuJouer();
        break;
    case 2:
        afficherScores();
        break;
    case 3:
        menuOptions();
        break;
    case 4:
        choix = 0;
        break;
    default:
        choix = 0;
        break;
    }
    return choix;
}

void lancement()
{
    char color[9];
    FILE* fichier = NULL;
    fichier = fopen("data/color.pom", "r");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    fgets(color, 9, fichier);
    system(color);

    srand(time(NULL));

    fclose(fichier);
}

int bite()
{
    int continuer = 1;

    system(CLEAR);
    while(continuer)
    {
        printf("bite");
        system("color 00");
        system("color 10");
        printf("bite");
        system("color 01");
        system("color 21");
        printf("bite");
        system("color 21");
        system("color 02");
        printf("bite");
        system("color 32");
        system("color 03");
        printf("bite");
        system("color 43");
        system("color 04");
        printf("bite");
        system("color 54");
        system("color 05");
        printf("bite");
        system("color 65");
        system("color 06");
        printf("bite");
        system("color 76");
        system("color 07");
        printf("bite");
        system("color 87");
        system("color 08");
        printf("bite");
        system("color 98");
        system("color 09");
        printf("bite");
        system("color a9");
        system("color 0a");
        printf("bite");
        system("color ba");
        system("color 0b");
        printf("bite");
        system("color cb");
        system("color 0c");
        printf("bite");
        system("color dc");
        system("color 0d");
        printf("bite");
        system("color ed");
        system("color 0e");
        printf("bite");
        system("color fe");
        system("color 0f");
        printf("bite");
    }
    return 1;
}
