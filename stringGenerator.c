#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarTamanhoString()
{
    return rand() % 100 + 1;
}

void printRandomString()
{
    int string_tam = gerarTamanhoString();
    char * string = (char*) calloc((string_tam+1), sizeof(char));

    int i;
    for(i = 0; i < string_tam; i++)
    {
        string[i] = 'A' + (rand() % 26);
    }
    string[i] = '\0';

    FILE * saida = fopen("strings.txt", "a+");
    fprintf(saida,"%s\n", string);
    fclose(saida);
    free(string);
}

int main()
{
    srand(time(NULL));
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        printRandomString();

    return 0;
}
