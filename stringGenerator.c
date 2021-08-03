#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarTamanhoString()
{
    return rand() % 100 + 1;
}

void fileprintRandomString(FILE * output)
{
    int string_tam = gerarTamanhoString();
    char * string = (char*) calloc((string_tam+1), sizeof(char));

    int i;
    for(i = 0; i < string_tam; i++)
    {
        string[i] = 'A' + (rand() % 26);
    }
    string[i] = '\0';

    fprintf(output,"%s\n", string);
    free(string);
}

int main()
{
    srand(time(NULL));
    int N;
    scanf("%d", &N);
    FILE * output = fopen("strings.txt", "w");
    for(int i = 0; i < N; i++)
        fileprintRandomString(output);

    fclose(output);

    return 0;
}
