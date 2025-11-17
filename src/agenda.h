#ifndef AGENDA_H
#define AGENDA_H

#define MAX_NOME 100
#define MAX_TELEFONE 20
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

enum Opcao {
    OP_CONTATOS = 1,
    OP_COMPROMISSOS = 2,
    OP_TAREFAS = 3,
    OP_SAIR = 4
};

#endif