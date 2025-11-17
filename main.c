#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOME 100
#define MAX_TELEFONE 50
#define MAX_EMAIL 100
#define MAX_DESCRICAO 500

#define MAX_VETOR 20

typedef struct structContato
{
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
} Contato;

typedef struct structCompromisso
{
    char data[10];
    char hora[5];
    char descricao[MAX_DESCRICAO];
} Compromisso;

typedef struct structTarefa
{
    char titulo[MAX_NOME];
    unsigned int prioridade;
    unsigned int status;
} Tarefa;

enum Opcao {
    OP_CONTATOS = 1,
    OP_COMPROMISSOS = 2,
    OP_TAREFAS = 3,
    OP_SAIR = 4
};

void menu_principal(void);
void menu_secundario(void);

int main(void)
{
    Contato contatos[MAX_VETOR] = {};
    Compromisso compromissos[MAX_VETOR] = {};
    Tarefa tarefas[MAX_VETOR] = {};
 
    menu_principal();

    return 0;
}

void menu_principal(void)
{
    unsigned int opcao;
    bool pronto = false;

    system("cls");

    puts("---------------------------");
    puts("          AGENDA           ");
    puts("---------------------------");

    puts("1. Agenda de Contatos");
    puts("2. Agenda de Compromissos");
    puts("3. Agenda de Tarefas");
    puts("4. Sair do Programa");

    printf("Escolha uma opcao: ");
    scanf(" %d", &opcao);

    while(!pronto)
    {
        switch (opcao)
        {
        case OP_CONTATOS:
            menu_secundario();
            break;
        case OP_COMPROMISSOS:

            break;
        case OP_TAREFAS:

            break;
        case OP_SAIR: {
            pronto = true;
            break;
        }
        default: {
            puts("Opcao invalida!");
            break;
        }
        }
    }
}

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