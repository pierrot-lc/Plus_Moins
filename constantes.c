#include <stdlib.h>
#include <stdio.h>

void viderBuffer()
{
    int caractere = 0;
    while(caractere != '\n' && caractere != EOF)
        caractere = getchar();
}
