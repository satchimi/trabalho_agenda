#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include "leitor_string.h"

int adicionarContato(Contato contatos[], int quant)
{
    if (quant >= MAX_VETOR) {
        printf("\nA agenda está cheia.\n");
        system("cls");
        return 0;
    }

    Contato *contato = &contatos[quant];

    printf("\n--- Cadastro de Contato ---\n");

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o nome do contato a ser salvo: ");

            if (ler_linha(contato->nome, MAX_NOME) == 0) {
                puts("\nO campo de nome nao pode estar vazio!");
                continue;
            }
            pronto = true;
        }
    }

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o seu telefone. (Ex: 86994523978): ");

            if (ler_palavra(contato->telefone, MAX_TELEFONE) == 0) {
                puts("\nO campo de telefone nao pode estar vazio!");
                continue;
            }
            pronto = true;
        }
    }

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o seu e-mail: ");

            if (ler_palavra(contato->email, MAX_EMAIL) == 0) {
                puts("\nO campo de email nao pode estar vazio!");
                continue;
            }

            if (email_check(contato->email) == false) {
                puts("\nFormato de email errado! Formato certo: nome@servidor.dominio");
                continue;
            }
            pronto = true;
        }
    }

    printf("\n");

    system("cls");
    return 1;
}

int listaContatos(Contato contatos[], int quant)
{
    printf("\n--- Lista de Contatos ---\n");

    if (quant == 0) {
        printf("\nNenhum contato cadastrado.\n\n");

        return 0;
    }

    for (int i = 0; i < quant; i++) {
        printf("\n[Contato %d]\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("E-mail: %s\n\n", contatos[i].email);
    }

    return 1;
}

int pesquisarContato(Contato contatos[], int quant)
{
    char nomeBuscado[MAX_NOME];
    int i = 0;

    printf("\nDigite o nome que deseja pesquisar: ");
    ler_linha(nomeBuscado, MAX_NOME);

    for (int j = 0; j < quant; j++) {
        if (strcmp(nomeBuscado, contatos[j].nome) == 0) {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", contatos[j].nome);
            printf("Telefone: %s\n", contatos[j].telefone);
            printf("E-mail: %s\n\n", contatos[j].email);

            i++;
        }
    }

    if (i == 0)
        printf("\nContato nao encontrado.\n\n");

    return i;
}

int deletarContato(Contato contatos[], int* quant)
{
    int id;

    if (listaContatos(contatos, *quant) == 0) return 0;

    printf("Digite o numero do contato que voce quer deletar: ");
    scanf(" %d", &id);

    while(getchar() != '\n');

    if (id < 1 || id > *quant) {
        printf("\nErro: Contato %d nao existe\n\n", id);
        return 0;
    }

    for ( ; id < *quant; id++) {
        contatos[id - 1] = contatos[id];
    }

    (*quant)--;

    printf("\nContato %d deletado.\n\n", id);

    return 1;
}

bool email_check(const char *email)
{
    bool tem_at = false; //at <-> @
    bool tem_dominio = false; //dominio <-> .com
    int char_antes_da_at = 0;
    int char_depois_da_at = 0;
    int char_depois_do_dominio = 0;

    while (*email != '\0')
    {
        if (*email == '@') {
            tem_at = true;
        }
        if (*email == '.') {
            tem_dominio = true;
        }
        else if (tem_at) {
            if (tem_dominio)
                char_depois_do_dominio++;
            char_depois_da_at++;
        }
        else char_antes_da_at++;

        email++;
    }

    return char_antes_da_at > 0 &&
           char_depois_da_at > 0 &&
           char_depois_do_dominio > 0 ? true : false;
}