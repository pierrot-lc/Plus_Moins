#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "constantes.h"
#include "jouer.h"
#include "score.h"

int menuJouer()
{
    int choix;

    while(choix < 1 || choix > 3)
    {
        system(CLEAR);

        printf("Choisissez votre mode de jeu :\n");
        printf("1. Mode solo\n2. Mode duo\n3. Menu principal\n\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        viderBuffer();
    }

    switch(choix)
    {
    case 1:
        choixNiveaux();
        system(CLEAR);
        break;
    case 2:
        jouerDuo();
        break;
    case 3:
        return 1;
        break;
    default:
        return 0;
        break;
    }
    return 1;
}

void choixNiveaux()
{
    int niveau = 0;

    do
    {
        system(CLEAR);

        printf("Choisissez un niveau :\n");
        printf("1. Niveau 1\n2. Niveau 2\n3. Niveau 3\n4. Niveau personalise\n\n");
        printf("Votre choix : ");
        scanf("%d", &niveau);

        viderBuffer();
    }
    while(niveau < 1 || niveau > 4);

    jouerSolo(niveau);
}

void jouerSolo(int niveau)
{
    const int MIN = 1;
    int Max = 0, nombreMystere = 0, nombreUtilisateur = 0, score = 0;

    system(CLEAR);

    switch(niveau)
    {
    case 1:
        Max = 100;
        break;
    case 2:
        Max = 1000;
        break;
    case 3:
        Max = 10000;
        break;
    case 4:
        printf("Choississez la limite maximale du nombre mystere !\n");
        printf("Limite = ");
        scanf("%d", &Max);
        break;
    default:
        Max = 100;
        break;
    }

    nombreMystere = (rand() % (Max - MIN + 1)) + MIN;
    system(CLEAR);
    printf("Trouvez le nombre mystere entre %d et %d !\n", MIN, Max);
    do
    {
        nombreUtilisateur = 0;

        printf("Nombre de coups : %d\n", score);
        printf("Votre proposition : ");
        scanf("%d", &nombreUtilisateur);
        viderBuffer();

        while(nombreUtilisateur < MIN || nombreUtilisateur > Max)
        {
            system(CLEAR);
            printf("Trouvez le nombre mystere entre %d et %d !\n", MIN, Max);
            printf("Nombre de coups : %d\n", score);
            printf("Votre proposition : ");
            scanf("%d", &nombreUtilisateur);
            viderBuffer();
        }

        score++;

        if(nombreUtilisateur < nombreMystere)
            printf("C'est plus !\n\n");
        else if (nombreUtilisateur > nombreMystere)
            printf("C'est moins !\n\n");
        else
            printf("Bravo ! Vous avez trouve le nombre mystere en %d de coups !\n\n", score);
    }
    while(nombreUtilisateur != nombreMystere);

    if(niveau == 4)
    {
        printf("Appuyez sur entree pour continuer ...");
        getchar();
    }
    else
        ajouterScore(niveau, score);
}

void jouerDuo()
{
    unsigned int nombreMystere = 0, proposition = 0, score = 0;

    system(CLEAR);
    printf("Mode deux joueurs, le premier tape le nombre mystere et le deuxieme trouve doit trouver le nombre.\n\n");
    printf("Appuyez sur entree pour continuer ...\n");
    getchar();
    system(CLEAR);

    printf("Tapez le nombre mystere : ");
    scanf("%d", &nombreMystere);

    system(CLEAR);
    printf("Trouvez le nombre !\n");

    do
    {
        viderBuffer();
        printf("Nombre de coups : %d\n", score);
        printf("Votre proposition : ");
        scanf("%d", &proposition);
        viderBuffer();
        score++;

        if(proposition < nombreMystere)
            printf("C'est plus !\n\n");
        else if(proposition > nombreMystere)
            printf("C'est moins !\n\n");
        else
            printf("Bravo ! Vous avez trouve le nombre en %d de coups !\n\n", score);
    }
    while(nombreMystere != proposition);

    printf("Appuyez sur entree pour continuer ...\n");
    getchar();
}
