#include <stdio.h>
#include "leitor_string.h"

int ler_linha(char* str, int n)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int ler_palavra(char *str, int n)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') { i++; break; }
        else if (i < n) { str[i++] = ch; }
    }
    str[i] = '\0';

    return i;
}