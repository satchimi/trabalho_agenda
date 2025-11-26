#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "agenda.h"
#include "leitor_input.h"


// Função para validar formato básico de e-mail
bool email_check(const char *email)
{
    bool tem_at = false;          // verifica se existe @
    bool tem_dominio = false;     // verifica se existe .
    int char_antes_da_at = 0;     // caracteres antes do @
    int char_depois_da_at = 0;    // caracteres depois do @
    int char_depois_do_dominio = 0; // caracteres após o ponto

    // Percorre cada caractere do e-mail
    while (*email != '\0')
    {
        if (*email == '@') {
            tem_at = true;
        }
        else if (*email == '.') {
            tem_dominio = true;
        }
        else if (tem_at) {
            if (tem_dominio)
                char_depois_do_dominio++;
            char_depois_da_at++;
        }
        else char_antes_da_at++;

        email++; // avança para o próximo caractere
    }

    // Regras básicas para e-mail válido
    bool email_valido = char_antes_da_at > 0 &&
                        char_depois_da_at > 0 &&
                        char_depois_do_dominio > 0 ? true : false;

    return email_valido;
}

int validarTelefone(char *numero) {

    // remove espaços vazios nas laterais
    numero[strcspn(numero, "\n")] = 0;

    // remover espaços
    char temp[50];
    int idx = 0;
    int i = 0;
    while (numero[i] != '\0') {
        if (numero[i] != ' ')
        temp[idx++] = numero[i];
        i++;
    }
    temp[idx] = '\0';
    strcpy(numero, temp);

    // Adicionar caracteres nas posições específicas caso não existam
    if (numero[0] != '(') {
        adicionar_string(numero, 0, '(');
    }
    if (numero[3] != ')') {
        adicionar_string(numero, 3, ')');
    }
    if (numero[9] != '-') {
        adicionar_string(numero, 9, '-');
    }

    adicionar_string(numero, 4, ' ');

    return 0;
}

int formatarHora (char *hora) {

     // remove espaços vazios nas laterais
    hora[strcspn(hora, "\n")] = 0;

    // remover espaços
        char temp[50];
    int idx = 0;
    int i = 0;
    while (hora[i] != '\0') {
        if (hora[i] != ' ') {
        temp[idx++] = hora[i];
        i++;
        }
    }
    temp[idx] = '\0';
    strcpy(hora, temp);

    // Adicionar caractere ":" nas posição específica caso não exista
    if (hora[2] != ':') {
        adicionar_string(hora, 2, ':');
    }
}

int validarHora (char *hora) {
    for (int i = 0; hora[i] != '\0'; i++) {
        if (!isdigit(hora[i])) {
            return false;
        } else {
            return true;
        }
    }
}

//funcao helper
bool anoBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    }
    return false;
}

bool data_check(const char* data)
{
    int dia = atoi(data);
    data += 3;
    int mes = atoi(data);
    data += 3;
    int ano = atoi(data);

    if (ano < 1 || mes < 1 || mes > 12 || mes < 1) {
        return false;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && anoBissexto(ano)) {
        diasNoMes[2] = 29;
    }

    if (dia > diasNoMes[mes]) {
        return false;
    }

    return true;
}

bool hora_check(const char* hora)
{
    int horas = atoi(hora);
    hora += 3;
    int minutos = atoi(hora);

    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
        return false;
    }

    return true;
}