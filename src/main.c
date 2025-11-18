#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "agenda.h"

#define MAX_VETOR 20

void menu_principal(int* opcao);
void menu_selecionar_operacao(int tipo_agenda, int* operacao);

void operacao_contatos(int operacao);
void operacao_compromissos(int operacao);
void operacao_tarefas(int operacao);

//var que controla quando o programa deve terminar
bool terminado = false;

int main(void)
{
    int opcao_agenda, opcao_operacao;

    Contato contatos[MAX_VETOR] = {};
    Compromisso compromissos[MAX_VETOR] = {};
    Tarefa tarefas[MAX_VETOR] = {};

    while(!terminado)
    {
        menu_principal(&opcao_agenda);

        switch (opcao_agenda)
        {
        case OP_CONTATOS:
            
            menu_selecionar_operacao(OP_CONTATOS, &opcao_operacao);

            operacao_contatos(opcao_operacao);

            break;

        case OP_COMPROMISSOS:

            menu_selecionar_operacao(OP_COMPROMISSOS, &opcao_operacao);

            operacao_compromissos(opcao_operacao);

            break;

        case OP_TAREFAS:

            menu_selecionar_operacao(OP_TAREFAS, &opcao_operacao);

            operacao_tarefas(opcao_operacao);

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
//* variavel de opcao recebida.                                            *
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

//**************************************************************************
//* Recebe uma variavel que indica qual o tipo de agenda escolhido e uma   *
//* variavel de operacao por referencia. Imprime o menu de acordo com o    *
//* tipo de agenda e pede ao usuario para escolher a operacao. O valor     *
//* escolhido é passado à variavel de operacao recebida.                   *
//**************************************************************************
void menu_selecionar_operacao(int tipo_agenda, int* operacao)
{
    char* agenda_op_nomes[3] = {"contato", "compromisso", "tarefa"};

    char* agenda = agenda_op_nomes[tipo_agenda - 1];

    printf("1. Adicionar novo(a) %s\n", agenda);
    printf("2. Listar todos(as) os(as) %ss\n", agenda);
    printf("3. Buscar um(a) %s especifico(a)\n", agenda);
    puts("4. Voltar ao menu anterior");
    puts("5. Sair do sistema");

    printf("\nEscolha uma opcao: ");
    scanf(" %d", operacao);
}

void operacao_contatos(int operacao)
{
    
}

void operacao_compromissos(int operacao)
{

}

void operacao_tarefas(int operacao)
{

}