#include <stdio.h>
#include <stdlib.h>

#include "options.h"
#include "constantes.h"

void menuOptions()
{
    int choix = 0;

    while(choix < 1 || choix > 3)
    {
        system(CLEAR);
        printf("1. Reinitialiser les meilleurs scores\n2. Changer la couleur de texte\n3. Menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
    }

    switch(choix)
    {
    case 1:
        menuReinitialise();
        break;
    case 2:
        changerCouleur();
        break;
    case 3:
        break;
    default:
        break;
    }
}

void menuReinitialise()
{
    int choix = 0;

    while(choix < 1 || choix > 5)
    {
        system(CLEAR);
        printf("1. Reinitialiser les scores du niveau 1\n2. Reinitialiser les scores du niveau 2\n3. Reinitialiser les scores du niveau 3\n4. Reinitialiser tous les scores\n5. Menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
    }

    switch(choix)
    {
    case 1:
        reinitialiseScores(1);
        break;
    case 2:
        reinitialiseScores(2);
        break;
    case 3:
        reinitialiseScores(3);
        break;
    case 4:
        reinitialiseScores(1);
        reinitialiseScores(2);
        reinitialiseScores(3);
        break;
    case 5:
        break;
    default:
        exit(EXIT_FAILURE);
    }
}

void reinitialiseScores(int niveau)
{
    FILE* fichier = NULL;

    switch(niveau)
    {
    case 1:
        fichier = fopen("data/scores1.pom", "w+");
        if(fichier == NULL)
            exit(EXIT_FAILURE);

        fprintf(fichier, "5 5 6 7 10\nSamkio Mangetachaussette PostMortem Monbey Vicerator");
        break;
    case 2:
        fichier = fopen("data/scores2.pom", "w+");
        if(fichier == NULL)
            exit(EXIT_FAILURE);

        fprintf(fichier, "6 7 8 11 15\nMangetachaussette Monbey Samkio PostMortem Vicerator");
        break;
    case 3:
        fichier = fopen("data/scores3.pom", "w+");
        if(fichier == NULL)
            exit(EXIT_FAILURE);

        fprintf(fichier, "8 9 12 15 20\nMonbey Mangetachaussette PostMortem Samkio Vicerator");
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }
    fclose(fichier);
}

int changerCouleur()
{
    int choix = 0, continuer = 1;
    char color[9];

    color[0] = 'c';
    color[1] = 'o';
    color[2] = 'l';
    color[3] = 'o';
    color[4] = 'r';
    color[5] = ' ';
    color[6] = '0';
    color[8] = '\0';

    while(continuer)
    {
        choix = 0;
        while(choix < 1 || choix > 9)
        {
            system(CLEAR);
            printf("Couleur du texte :\n");
            printf("1. Blanc\n2. Bleu\n3. Vert\n4. Rouge\n5. Cyan\n6. Jaune\n7. Marron\n8. Kaki\n9. Menu principal\n");
            printf("Votre choix : ");
            scanf("%d", &choix);
            viderBuffer();
        }
        switch(choix)
        {
        case 1:
            color[7] = '7';
            inscrireCouleur(color);
            break;
        case 2:
            color[7] = '1';
            inscrireCouleur(color);
            break;
        case 3:
            color[7] = '2';
            inscrireCouleur(color);
            break;
        case 4:
            color[7] = 'c';
            inscrireCouleur(color);
            break;
        case 5:
            color[7] = 'b';
            inscrireCouleur(color);
            break;
        case 6:
            color[7] = 'e';
            inscrireCouleur(color);
            break;
        case 7:
            color[7] = '4';
            inscrireCouleur(color);
            break;
        case 8:
            color[7] = '6';
            inscrireCouleur(color);
            break;
        case 9:
            continuer = 0;
            break;
        }
        system(color);
    }
    return 1;
}

int inscrireCouleur(char color[])
{
    FILE* fichier = NULL;
    fichier = fopen("data/color.pom", "w+");

    if(fichier == NULL)
        return 0;

    fprintf(fichier, "%s", color);

    fclose(fichier);
    return 0;
}
