#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "agenda.h"

#define MAX_VETOR 20

void menu_principal(int* opcao);

int main(void)
{
    //var que controla quando o programa deve terminar
    bool terminado = false;

    int opcao;

    Contato contatos[MAX_VETOR] = {};
    Compromisso compromissos[MAX_VETOR] = {};
    Tarefa tarefas[MAX_VETOR] = {};

    while(!terminado)
    {

        menu_principal(&opcao);

        switch (opcao)
        {
        case OP_CONTATOS:
            break;
        case OP_COMPROMISSOS:

            break;
        case OP_TAREFAS:

            break;
        case OP_SAIR:
            terminado = true;
            break;
        default:
            puts("Opcao invalida!");
            break;
        }
    }

    return 0;
}


//**************************************************************************
//* Recebe uma variavel de opcao por referencia, imprime as opções na tela *
//* e pede ao usuario para escolher a opcao. O valor escolhido é passado à *
//* variavel recebida.                                                     *
//**************************************************************************
void menu_principal(int* opcao)
{

    puts("--------------------------");
    puts("          AGENDA          ");
    puts("--------------------------");

    puts("1. Agenda de Contatos");
    puts("2. Agenda de Compromissos");
    puts("3. Agenda de Tarefas");
    puts("4. Sair do Programa");

    printf("\nEscolha uma opcao: ");
    scanf(" %d", opcao);
}

/*
void menu_secundario(void)
{
    //TESTE
    unsigned int opcao;

    system("cls");


    puts("---------------------------");
    puts("          OPCAO            ");
    puts("---------------------------");

    puts("1. Adicionar novo registro");
    puts("2. Listar todos");
    puts("3. Buscar registro");
    puts("4. Voltar");
    puts("5. Sair");

    printf("Escolha uma opcao: ");
    scanf(" %d", &opcao);

    
}
*/