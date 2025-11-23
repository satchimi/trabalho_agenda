#ifndef AGENDA_H
#define AGENDA_H

#include <stdbool.h>

//---------MODULO AGENDA-----------

//Tamanho maximo do vetor de cada tipo de agenda
#define MAX_VETOR 20

#define MAX_NOME 100
#define MAX_TELEFONE 12
#define MAX_EMAIL 100
#define MAX_DESCRICAO 500
#define MAX_TITULO 100

typedef struct structContato
{
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
} Contato;

typedef struct structCompromisso
{
    char data[11];
    char hora[6];
    char descricao[MAX_DESCRICAO];
} Compromisso;

typedef struct structTarefa
{
    char titulo[MAX_TITULO];
    unsigned int prioridade;
    unsigned int status;
} Tarefa;

enum AgendaOpcao {
    OP_CONTATOS = 1,
    OP_COMPROMISSOS = 2,
    OP_TAREFAS = 3,
    OP_SAIR = 4
};

enum AgendaOperacao {
    OPER_ADICIONAR = 1,
    OPER_LISTAR = 2,
    OPER_BUSCAR = 3,
    OPER_DELETAR = 4,
    OPER_VOLTAR = 5,
    OPER_SAIR = 6
};

int adicionarContato(Contato contatos[], int quant);
int listaContatos(Contato contatos[], int quant);
int pesquisarContato(Contato contatos[], int quant);
int deletarContato(Contato contatos[], int* quant);

bool email_check(const char *email);

#endif