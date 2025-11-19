#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "agenda.h"

//Tamanho maximo do vetor de cada tipo de agenda
#define MAX_VETOR 20

void menu_secundario(int tipo_agenda);

void menu_selecionar_opcao(int* opcao);
void menu_selecionar_operacao(int tipo_agenda, int* operacao);

void operacao_contatos(int operacao);
void operacao_compromissos(int operacao);
void operacao_tarefas(int operacao);

//vetor de ponteiros para funcoes de operação de tarefas
void (*operacoes_agenda[3])(int) = {&operacao_contatos, &operacao_compromissos, &operacao_tarefas};

//var que controla quando o programa deve terminar
bool terminado_global = false;

//var globais das agendas
Contato contatos[MAX_VETOR] = {};
Compromisso compromissos[MAX_VETOR] = {};
Tarefa tarefas[MAX_VETOR] = {};

int main(void)
{
    int opcao_agenda;

    while(!terminado_global)
    {

        menu_selecionar_opcao(&opcao_agenda);

        switch (opcao_agenda)
        {
        case OP_CONTATOS: case OP_COMPROMISSOS: case OP_TAREFAS:

            menu_secundario(opcao_agenda);

            break;

        case OP_SAIR:

            terminado_global = true;

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
void menu_selecionar_opcao(int* opcao)
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

    while(getchar() != '\n');
}

//*************************************************************
//* Controla o menu que aparece apos escolher o tipo de agenda *
//**************************************************************
void menu_secundario(int tipo_agenda)
{
    //var que controla quando encerrar o menu secundario
    bool terminado_menu_sec = false;

    int opcao_operacao;

    while (!terminado_menu_sec)
    {

        menu_selecionar_operacao(tipo_agenda, &opcao_operacao);
    
        switch (opcao_operacao)
        {
        case OPER_ADICIONAR: case OPER_BUSCAR: case OPER_LISTAR:

            operacoes_agenda[tipo_agenda - 1](opcao_operacao);

            break;

        case OPER_VOLTAR:
            
            terminado_menu_sec = true;

            break;
    
        case OPER_SAIR:
    
            terminado_menu_sec = true;
            terminado_global = true;

            break;
        
        default:
            
            puts("Operacao invalida!");
    
            break;
        }
    }



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

    while(getchar() != '\n');
}

void operacao_contatos(int operacao)
{
    // A agenda de contatos fica guardada aqui
    static int quantContatos = 0;

    switch (operacao)
    {
    case OPER_ADICIONAR:
        quantContatos += adicionarContato(contatos, quantContatos);
        break;

    case OPER_LISTAR:
        QntContatos(contatos, quantContatos);
        break;

    case OPER_BUSCAR:
        pesquisarContato(contatos, quantContatos);
        break;
    }

}

void operacao_compromissos(int operacao)
{

}

void operacao_tarefas(int operacao)
{

}