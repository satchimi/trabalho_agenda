#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

int adicionarContato(Contato *c, int quant)
{
    if (quant < MAX_VETOR)
    {
        printf("\n--- Cadastro de Contato ---\n");

        printf("\nDigite o nome do contato a ser salvo: ");
        scanf("%100[^\n]", c[quant].nome);

        printf("\nDigite o seu telefone: ");
        scanf("%s", c[quant].telefone);

        printf("Digite o seu e-mail: ");
        scanf("%s", c[quant].email);

        return 1;
    }
    else
    {
        printf("\nA agenda está cheia.\n");
        return 0;
    }
}

void QntContatos(Contato *c, int quant)
{
    printf("\n--- Lista de Contatos ---\n");

    if (quant == 0)
    {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    for (int i = 0; i < quant; i++)
    {
        printf("\nContato %d:\n", i + 1);
        printf("Nome: %s\n", c[i].nome);
        printf("Telefone: %s\n", c[i].telefone);
        printf("E-mail: %s\n", c[i].email);
        printf("\n");
    }
}

void pesquisarContato(Contato *c, int quant)
{
    char nomeBuscado[21];
    printf("\nDigite o nome que deseja pesquisar: ");
    scanf("%s", nomeBuscado);

    for (int i = 0; i < quant; i++)
    {
        if (strcmp(nomeBuscado, c[i].nome) == 0)
        {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", c[i].nome);
            printf("Telefone: %s\n", c[i].telefone);
            printf("E-mail: %s\n", c[i].email);
            return;
        }
    }

    printf("\nContato não encontrado.\n");
}

//PARA FAZER: implementar as funcoes que fazem as operacoes das tarefas (inserir, listar, buscar)