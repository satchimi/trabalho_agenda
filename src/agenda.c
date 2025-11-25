#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include "leitor_string.h"

// Função para adicionar um novo contato no vetor
int adicionarContato(Contato contatos[], int quant)
{
    // Verifica se o número atual de contatos atingiu o limite máximo
    if (quant >= MAX_VETOR) {
        printf("\nA agenda está cheia.\n");
        system("cls"); // limpa a tela
        return 0;      // não adicionou
    }

    // Ponteiro para o local onde o novo contato será salvo
    Contato *contato = &contatos[quant];

    printf("\n--- Cadastro de Contato ---\n");

    // ----- Leitura do nome -----
    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o nome do contato a ser salvo: ");

            // ler_linha retorna 0 se o usuário apenas apertar ENTER
            if (ler_linha(contato->nome, MAX_NOME) == 0) {
                puts("\nO campo de nome nao pode estar vazio!");
                continue; // repete a pergunta
            }
            pronto = true; // nome preenchido
        }
    }

    // ----- Leitura do telefone -----
    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o seu telefone. (Ex: 5586994523978): ");

            // ler_palavra lê até o primeiro espaço; retorno 0 significa vazio
            if (ler_palavra(contato->telefone, MAX_TELEFONE) == 0) {
                puts("\nO campo de telefone nao pode estar vazio!");
                continue;
            }
            pronto = true;
        }
    }

    // ----- Leitura do e-mail -----
    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o seu e-mail: ");

            if (ler_palavra(contato->email, MAX_EMAIL) == 0) {
                puts("\nO campo de email nao pode estar vazio!");
                continue;
            }

            // Valida o formato do e-mail
            if (email_check(contato->email) == false) {
                puts("\nFormato de email errado! Formato certo: nome@servidor.dominio");
                continue;
            }
            pronto = true;
        }
    }

    printf("\n");

    system("cls"); // limpa a tela após o cadastro
    return 1;      // cadastro concluído
}


// Função para listar todos os contatos
int listaContatos(Contato contatos[], int quant)
{
    printf("\n--- Lista de Contatos ---\n");

    // Se não existem contatos cadastrados
    if (quant == 0) {
        printf("\nNenhum contato cadastrado.\n\n");
        return 0;
    }

    // Percorre todos os contatos e exibe
    for (int i = 0; i < quant; i++) {
        printf("\n[Contato %d]\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("E-mail: %s\n\n", contatos[i].email);
    }

    return 1;
}


// Função para pesquisar um contato pelo nome
int pesquisarContato(Contato contatos[], int quant)
{
    char nomeBuscado[MAX_NOME];
    int encontrados = 0;

    printf("\nDigite o nome que deseja pesquisar: ");
    ler_linha(nomeBuscado, MAX_NOME);

    // Procura contato com nome exatamente igual ao digitado
    for (int j = 0; j < quant; j++) {
        if (strcmp(nomeBuscado, contatos[j].nome) == 0) {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", contatos[j].nome);
            printf("Telefone: %s\n", contatos[j].telefone);
            printf("E-mail: %s\n\n", contatos[j].email);

            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("\nContato nao encontrado.\n\n");

    return encontrados; // número de contatos encontrados
}


// Função para deletar um contato pelo número da lista
int deletarContato(Contato contatos[], int* quant)
{
    int id;

    // Primeiro exibe a lista; se estiver vazia, encerra
    if (listaContatos(contatos, *quant) == 0) return 0;

    printf("Digite o numero do contato que voce quer deletar: ");
    scanf(" %d", &id);

    while(getchar() != '\n'); // limpa buffer do teclado

    // Se o número informado não existe
    if (id < 1 || id > *quant) {
        printf("\nErro: Contato %d nao existe\n\n", id);
        return 0;
    }

    // "Empurra" os contatos para cima, sobrescrevendo o removido
    for ( ; id < *quant; id++) {
        contatos[id - 1] = contatos[id];
    }

    (*quant)--; // diminui o total de contatos após o usuario deletar um escolhido

    printf("\nContato %d deletado.\n\n", id);

    return 1;
}


// Função para validar formato básico de e-mail
bool email_check(const char *email)
{
    bool tem_at = false;          // verifica se existe @
    bool tem_dominio = false;     // verifica se existe .
    int char_antes_da_at = 0;     // caracteres antes do @
    int char_depois_da_at = 0;    // caracteres depois do @
    int char_depois_do_dominio = 0; // caracteres após o ponto

    // Percorre cada caractere do e-mail
    while (*email != '\0')
    {
        if (*email == '@') {
            tem_at = true;
        }
        else if (*email == '.') {
            tem_dominio = true;
        }
        else if (tem_at) {
            if (tem_dominio)
                char_depois_do_dominio++;
            char_depois_da_at++;
        }
        else char_antes_da_at++;

        email++; // avança para o próximo caractere
    }

    // Regras básicas para e-mail válido
    bool email_valido = char_antes_da_at > 0 &&
                        char_depois_da_at > 0 &&
                        char_depois_do_dominio > 0 ? true : false;

    return email_valido;
}
