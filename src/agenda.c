#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include "leitor_string.h"

int adicionarContato(Contato contatos[], int quant)
{
    int i = 0;

    if (quant < MAX_VETOR)
    {
        printf("\n--- Cadastro de Contato ---\n");

        printf("\nDigite o nome do contato a ser salvo: ");
        ler_linha(contatos[quant].nome, MAX_NOME);

        printf("Digite o seu telefone: ");
        ler_linha(contatos[quant].telefone, MAX_TELEFONE);
        
        printf("Digite o seu e-mail: ");
        ler_palavra(contatos[quant].email, MAX_EMAIL);

        printf("\n");

        i = 1;
    }
    else
        printf("\nA agenda está cheia.\n");
    
    system("cls");
    return i;
}

void listaContatos(Contato contatos[], int quant)
{
    printf("\n--- Lista de Contatos ---\n");

    if (quant == 0) {
        printf("\nNenhum contato cadastrado.\n\n");

        return;
    }

    for (int i = 0; i < quant; i++) {
        printf("\n[Contato %d]\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("E-mail: %s\n\n", contatos[i].email);
    }
}

void pesquisarContato(Contato contatos[], int quant)
{
    char nomeBuscado[MAX_NOME];

    printf("\nDigite o nome que deseja pesquisar: ");
    ler_linha(nomeBuscado, MAX_NOME);

    for (int i = 0; i < quant; i++) {
        if (strcmp(nomeBuscado, contatos[i].nome) == 0) {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("E-mail: %s\n\n", contatos[i].email);

            return;
        }
    }

    printf("\nContato nao encontrado.\n\n");
}

void deletarContato(Contato contatos[], int* quant)
{
    int id;

    listaContatos(contatos, *quant);

    printf("Digite o numero do contato que voce quer deletar: ");
    scanf(" %d", &id);

    while(getchar() != '\n');

    if (id < 1 || id > *quant) {
        printf("\nErro: Contato %d nao existe\n\n", id);
        return;
    }

    for ( ; id < *quant; id++) {
        contatos[id - 1] = contatos[id];
    }

    (*quant)--;

    printf("\nContato %d deletado.\n\n", id);
}