#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "leitor_input.h"

int ler_linha(char* str, int n)
{
    int ch;
    int i = 0;

    n--;

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

    n--;

    bool tem_espaco = false;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            tem_espaco = true;
            continue;
        }
        if (i < n && !tem_espaco)
            str[i++] = ch;
    }
    str[i] = '\0';

    return i;
}

void adicionar_string(char *str, int pos, char carac) {
    int len = strlen(str);
    int i = len;

    // Move os elementos uma unidade para a direita
    while (i >= pos) {
        str[i + 1] = str[i];
        i--;
    }

    str[pos] = carac;
}

int ler_numero(int *num)
{
    int n = 0;

    if (scanf("%d", num) == 1)
        n = 1;
    
    while(getchar() != '\n');

    return n;
}

bool possui_letra(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            return true;
        }
    }
    return false;
}