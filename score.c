#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"

int ajouterScore(int niveau, int score)
{
    int fscore[5] = {0};
    int ajouter = 0, compteur = 0, i = 0, y = 0, choix = 0, numero = 0, t = 0, nombreLettres = 0, continuer = 1;
    char fpseudo[5][100], pseudo[100];
    char *positionEntree = NULL, *positionEspace = NULL;
    FILE* fichier = NULL;

    switch(niveau)
    {
    case 1:
        fichier = fopen("data/scores1.pom", "r");
        break;
    case 2:
        fichier = fopen("data/scores2.pom", "r");
        break;
    case 3:
        fichier = fopen("data/scores3.pom", "r");
        break;
    }

    if(fichier == NULL)
        exit(EXIT_FAILURE);

    rewind(fichier);
    fscanf(fichier, "%d %d %d %d %d\n%s %s %s %s %s", &fscore[0], &fscore[1], &fscore[2], &fscore[3], &fscore[4], fpseudo[0], fpseudo[1], fpseudo[2], fpseudo[3], fpseudo[4]);

    if(score < fscore[4])
    {
        while(choix < 1 || choix > 2)
        {
            printf("Bravo ! Votre score fait parti des 5 meilleurs !\nVoulez-vous l'enregistrer ?\n1. Oui\n2. Non\n");
            printf("Votre choix : ");
            scanf("%d", &choix);
            viderBuffer();

            if(choix == 2)
                return 0;

            system(CLEAR);
        }
    }
    else
    {
        printf("Appuyez sur entree pour continuer ...");
        getchar();
        return 0;
    }

    system(CLEAR);
    printf("Votre pseudo : ");
    if((fgets(pseudo, 100, stdin)) != NULL)
    {
        if((positionEntree = strchr(pseudo, '\n')) != NULL)
            *positionEntree = '\0';
        while(continuer)
        {
            i = 0;
            if(strchr(pseudo, ' ') != NULL)
            {
                while(pseudo[i] != ' ')
                    i++;
                while(pseudo[i] != NULL)
                {
                    pseudo[i] = pseudo[i + 1];
                    i++;
                }
            }
            else
                continuer = 0;
        }
    }


    for(i = 0; i < 5; i++)
    {
        compteur++;
        if(score < fscore[i])
            break;
    }

    y = 5 - compteur;//nombre de fois que dois etre répétée l'action suivante

    numero = 4;//Pour se placer sur la dernière case du tableau
    for(i = 0; i < y; i++)
    {
        fscore[numero] = fscore[numero - 1];
        numero--;
    }
    numero = 4;
    for(i = 0; i < y; i++)
    {
        for(t = 0; t < 100; t++)
        {
            fpseudo[numero][t] = fpseudo[numero - 1][t];
        }
        numero--;
    }

    fscore[numero] = score;

    for(i = 0; i < 100; i++)
    {
        fpseudo[numero][i] = pseudo[i];
    }
    fclose(fichier);

    switch(niveau)
    {
    case 1:
        fichier = fopen("data/scores1.pom", "w+");
        break;
    case 2:
        fichier = fopen("data/scores2.pom", "w+");
        break;
    case 3:
        fichier = fopen("data/scores3.pom", "w+");
        break;
    }
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    for(i = 0; i < 4; i++)
    {
        fprintf(fichier, "%d", fscore[i]);
        fputc(32, fichier);
    }
    fprintf(fichier, "%d", fscore[4]);
    fputc('\n', fichier);

    for(i = 0; i < 4; i++)
    {
        fprintf(fichier, "%s", fpseudo[i]);
        fputc(32, fichier);
    }
    fprintf(fichier, "%s", fpseudo[4]);

    fclose(fichier);
    return 1;
}

void afficherScores()
{
    int score1[5] = {0};
    int score2[5] = {0};
    int score3[5] = {0};
    char pseudo1[5][100];
    char pseudo2[5][100];
    char pseudo3[5][100];
    FILE* fichier = NULL;
    fichier = fopen("data/scores1.pom", "r");

    if(fichier == NULL)
        exit(EXIT_FAILURE);

    system(CLEAR);

    fscanf(fichier, "%d %d %d %d %d\n%s %s %s %s %s", &score1[0], &score1[1], &score1[2], &score1[3], &score1[4], pseudo1[0], pseudo1[1], pseudo1[2], pseudo1[3], pseudo1[4]);

    printf("Les meilleurs scores du niveau 1 sont :\n");
    printf("1. %d de %s\n2. %d de %s\n3. %d de %s\n4. %d de %s\n5. %d de %s\n\n", score1[0], pseudo1[0], score1[1], pseudo1[1], score1[2], pseudo1[2], score1[3], pseudo1[3], score1[4], pseudo1[4]);
    fclose(fichier);

    fichier = fopen("data/scores2.pom", "r");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    fscanf(fichier, "%d %d %d %d %d\n%s %s %s %s %s", &score2[0], &score2[1], &score2[2], &score2[3], &score2[4], pseudo2[0], pseudo2[1], pseudo2[2], pseudo2[3], pseudo2[4]);

    printf("Les meilleurs scores du niveau 2 sont :\n");
    printf("1. %d de %s\n2. %d de %s\n3. %d de %s\n4. %d de %s\n5. %d de %s\n\n", score2[0], pseudo2[0], score2[1], pseudo2[1], score2[2], pseudo2[2], score2[3], pseudo2[3], score2[4], pseudo2[4]);
    fclose(fichier);

    fichier = fopen("data/scores3.pom", "r");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    fscanf(fichier, "%d %d %d %d %d\n%s %s %s %s %s", &score3[0], &score3[1], &score3[2], &score3[3], &score3[4], pseudo3[0], pseudo3[1], pseudo3[2], pseudo3[3], pseudo3[4]);

    printf("Les meilleurs scores du niveau 3 sont :\n");
    printf("1. %d de %s\n2. %d de %s\n3. %d de %s\n4. %d de %s\n5. %d de %s\n\n", score3[0], pseudo3[0], score3[1], pseudo3[1], score3[2], pseudo3[2], score3[3], pseudo3[3], score3[4], pseudo3[4]);
    fclose(fichier);

    printf("\nAppuyez sur entree pour continuer ...\n");
    getchar();
}
