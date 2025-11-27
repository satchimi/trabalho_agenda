#ifndef AGENDA_H
#define AGENDA_H

#include <stdbool.h>

//---------MODULO AGENDA-----------

//Tamanho maximo do vetor de cada tipo de agenda
#define MAX_VETOR 20

#define MAX_NOME 100
#define MAX_TELEFONE 17
#define MAX_EMAIL 100
#define MAX_DATA 11
#define MAX_HORA 6
#define MAX_DESCRICAO 500
#define MAX_TITULO 100

// Estrutura que representa um contato na agenda
typedef struct structContato
{
    char nome[MAX_NOME];            // Nome do contato
    char telefone[MAX_TELEFONE];    // Número de telefone do contato
    char email[MAX_EMAIL];          // Endereço de e-mail do contato
} Contato;

// Estrutura que representa um compromisso
typedef struct structCompromisso
{
    char data[MAX_DATA];                  // Data do compromisso  
    char hora[MAX_HORA];                   // Hora do compromisso 
    char descricao[MAX_DESCRICAO];  // Descrição do compromisso
} Compromisso;

// Estrutura que representa uma tarefa
typedef struct structTarefa
{
    char titulo[MAX_TITULO];        // Título da tarefa
    int prioridade;        // Prioridade da tarefa 
    int status;            // Status da tarefa 
} Tarefa;

// Enumeração das opções principais do menu da agenda
enum AgendaOpcao {
    OP_CONTATOS = 1,     // Menu de contatos
    OP_COMPROMISSOS = 2, // Menu de compromissos
    OP_TAREFAS = 3,      // Menu de tarefas
    OP_SAIR = 4          // Finalizar o programa
};

// Enumeração das operações disponíveis dentro de cada menu
enum AgendaOperacao {
    OPER_ADICIONAR = 1,  // Adicionar um item
    OPER_LISTAR = 2,     // Listar itens existentes
    OPER_BUSCAR = 3,     // Buscar item específico
    OPER_DELETAR = 4,    // Excluir item
    OPER_VOLTAR = 5,     // Voltar ao menu anterior
    OPER_SAIR = 6        // Sair do sistema
};

// Função utilitária para validar o formato de um e-mail
int formatarTelefone(char *numero);
int validarHora (char *hora);
int formatarHora (char *hora);
bool email_check(const char *email);
bool data_check(const char* data);
bool hora_check(const char* hora);

#endif
