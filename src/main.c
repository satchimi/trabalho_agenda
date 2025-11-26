#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "agenda.h"
#include "leitor_input.h"

//--------------FUNCOES------------------------

static void menu_principal();
static void menu_secundario(int tipo_agenda);


static void menu_adicionar_contato();
static void menu_listar_contato();
static void menu_buscar_contato();
static void menu_deletar_contato();

static void menu_adicionar_compromisso();
static void menu_listar_compromisso();
static void menu_buscar_compromisso();
static void menu_deletar_compromisso();

static void menu_adicionar_tarefa();
static void menu_listar_tarefa();
static void menu_buscar_tarefa();
static void menu_deletar_tarefa();


//-------------VARIAVEIS-----------------

static void (*menu_agendas[3][4])(void) = {
    &menu_adicionar_contato,     &menu_listar_contato,     &menu_buscar_contato,     &menu_deletar_contato,
    &menu_adicionar_compromisso, &menu_listar_compromisso, &menu_buscar_compromisso, &menu_deletar_compromisso,
    &menu_adicionar_tarefa,      &menu_listar_tarefa,      &menu_buscar_tarefa,      &menu_deletar_tarefa
};

//var que controla quando o programa deve terminar
bool terminado_global = false;

//var das agendas
static Contato contatos[MAX_VETOR] = {};
static Compromisso compromissos[MAX_VETOR] = {};
static Tarefa tarefas[MAX_VETOR] = {};

static int qntdContatos = 0;
static int qntdCompromissos = 0;
static int qntdTarefas = 0;

//-----------------------------------------------------

int main(void)
{
    system("cls");
    
    while(!terminado_global) {
        menu_principal();
    }

    return 0;
}

//-----------DEFINICAO DAS FUNCOES---------------------

static void menu_principal()
{
    int tipo_agenda;

    puts("----------------------------------------------------------------");
    puts("               _    ____ _____ _   _ ____    _                  ");
    puts("              / \\  / ___| ____| \\ | |  _ \\  / \\             ");
    puts("    _____    / _ \\| |  _|  _| |  \\| | | | |/ _ \\    _____    ");
    puts("   |_____|  / ___ \\ |_| | |___| |\\  | |_| / ___ \\  |_____|   ");
    puts("           /_/   \\_\\____|_____|_| \\_|____/_/   \\_\\         ");
    puts("----------------------------------------------------------------");

    puts("1. Agenda de Contatos");
    puts("2. Agenda de Compromissos");
    puts("3. Agenda de Tarefas");
    puts("4. Sair do Programa");

    printf("\nEscolha uma opcao: ");
    scanf(" %d", &tipo_agenda);

    while(getchar() != '\n');

    switch (tipo_agenda) {
        case OP_CONTATOS: case OP_COMPROMISSOS: case OP_TAREFAS:
            system("cls");
            menu_secundario(tipo_agenda);
            break;
        case OP_SAIR:
            terminado_global = true;
            break;
        default:
            system("cls");
            puts("Opcao invalida!");
            break;
    }
}

//*************************************************************
//* Controla o menu que aparece apos escolher o tipo de agenda *
//**************************************************************
static void menu_secundario(int tipo_agenda)
{
    //var que controla quando sair do menu secundario
    bool sair_menu_sec = false;

    int tipo_operacao;

    while (!sair_menu_sec)
    {
        char* agenda_op_nomes[] = {"contato", "compromisso", "tarefa"};

        char* agenda = agenda_op_nomes[tipo_agenda - 1];

        printf("1. Adicionar novo(a) %s\n", agenda);
        printf("2. Listar todos(as) os(as) %ss\n", agenda);
        printf("3. Buscar um(a) %s especifico(a)\n", agenda);
        printf("4. Deletar %s\n", agenda);
        puts("5. Voltar ao menu anterior");
        puts("6. Sair do sistema");

        printf("\nEscolha uma opcao: ");
        scanf(" %d", &tipo_operacao);

        while(getchar() != '\n');
    
        switch (tipo_operacao) {
            case OPER_ADICIONAR: case OPER_BUSCAR: case OPER_LISTAR: case OPER_DELETAR:
                system("cls");
                menu_agendas[tipo_agenda - 1][tipo_operacao - 1]();
                break;
            case OPER_VOLTAR:
                system("cls");
                sair_menu_sec = true;
                break;
            case OPER_SAIR:
                sair_menu_sec = true;
                terminado_global = true;
                break;
            default:
                system("cls");
                puts("Operacao invalida!");
                break;
        }
    }
}




static void menu_adicionar_contato()
{
    // Verifica se o número atual de contatos atingiu o limite máximo
    if (qntdContatos >= MAX_VETOR) {
        printf("\nA agenda de contatos está cheia.\n");
        system("cls");
        return;
    }

    Contato contato;

    printf("\n--- Cadastro de Contato ---\n");

    // ----- Leitura do nome -----
    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o nome do contato a ser salvo: ");

            // ler_linha retorna 0 se o usuário apenas apertar ENTER
            if (ler_linha(contato.nome, MAX_NOME) == 0) {
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
            printf("\nDigite o seu telefone. (Ex: 86994523978): ");

            // ler_palavra lê até o primeiro espaço; retorno 0 significa vazio
            if (ler_palavra(contato.telefone, MAX_TELEFONE) == 0) {
                puts("\nO campo de telefone nao pode estar vazio!");
                continue;
            }

            if (possui_letra(contato.telefone)) {
                puts("\nO numero de telefone nao deve possuir letras!");
                continue;
            }
            validarTelefone(contato.telefone);
            pronto = true;
        }
    }

    // ----- Leitura do e-mail -----
    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o seu e-mail: ");

            if (ler_palavra(contato.email, MAX_EMAIL) == 0) {
                puts("\nO campo de email nao pode estar vazio!");
                continue;
            }

            // Valida o formato do e-mail
            if (email_check(contato.email) == false) {
                puts("\nFormato de email errado! Formato certo: nome@servidor.dominio");
                continue;
            }
            pronto = true;
        }
    }
    printf("\n");

    contatos[qntdContatos++] = contato;

    system("cls"); // limpa a tela após o cadastro
}

static void menu_listar_contato()
{
    printf("\n--- Lista de Contatos ---\n");

    // Se não existem contatos cadastrados
    if (qntdContatos == 0) {
        printf("\nNenhum contato cadastrado.\n\n");
        return;
    }

    // Percorre todos os contatos e exibe
    for (int i = 0; i < qntdContatos; i++) {
        printf("\n[Contato %d]\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("E-mail: %s\n\n", contatos[i].email);
    }
}

static void menu_buscar_contato()
{
    puts("menu buscar contato");
}

static void menu_deletar_contato()
{
    int id;

    if (qntdContatos == 0) {
        printf("\nNenhum contato cadastrado.\n\n");
        return;
    }

    menu_listar_contato();

    printf("Digite o numero do contato que voce quer deletar: ");
    scanf(" %d", &id);

    while(getchar() != '\n'); // limpa buffer do teclado

    // Se o número informado não existe
    if (id < 1 || id > qntdContatos) {
        printf("\nErro: Contato %d nao existe\n\n", id);
        return;
    }

    // "Empurra" os contatos para cima, sobrescrevendo o removido
    for ( ; id < qntdContatos; id++) {
        contatos[id - 1] = contatos[id];
    }

    qntdContatos--; // diminui o total de contatos após o usuario deletar um escolhido

    printf("\nContato %d deletado.\n\n", id);
}

static void menu_adicionar_compromisso()
{
    if (qntdCompromissos >= MAX_VETOR) {
        printf("\nA agenda de compromissos está cheia.\n");
        system("cls");
        return;
    }

    Compromisso compromisso;

    printf("\n--- Cadastro de Compromisso ---\n");

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite a data do compromisso (DD/MM/AAAA): ");

            if (ler_palavra(compromisso.data, MAX_DATA) == 0) {
                puts("\nO campo de data nao pode estar vazio!");
                continue;
            }

            if (possui_letra(compromisso.data)) {
                puts("\nA data nao deve possuir letras!");
                continue;
            }

            if (data_check(compromisso.data) == false) {
                puts("\nData invalida!");
                continue;
            }
            pronto = true;
        }
    }

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite a hora do compromisso (HH:MM): ");

            if (ler_palavra(compromisso.hora, MAX_HORA) == 0) {
                puts("\nO campo de hora nao pode estar vazio!");
                continue;
            }

            if (validarHora(compromisso.hora) == false) {
                puts("\nA hora nao pode conter letras!");
                continue;
            }
            formatarHora(compromisso.hora);

            if (hora_check(compromisso.hora) == false) {
                puts("\nHora invalida!");
                continue;
            }
            pronto = true;
        }
    }

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite a descricao do compromisso (Max. 500 caracteres): ");

            if (ler_linha(compromisso.descricao, MAX_DESCRICAO) == 0) {
                puts("\nO campo de descricao nao pode estar vazio!");
                continue;
            }
            pronto = true;
        }
    }
    printf("\n");

    compromissos[qntdCompromissos++] = compromisso;

    system("cls");
}

static void menu_listar_compromisso()
{
    printf("\n--- Lista de Compromissos ---\n");

    if (qntdCompromissos == 0) {
        printf("\nNenhum compromisso cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qntdCompromissos; i++) {
        printf("\n[Compromisso %d]\n", i + 1);
        printf("Data: %s\n", compromissos[i].data);
        printf("Hora: %s\n", compromissos[i].hora);
        printf("Descricao: %s\n\n", compromissos[i].descricao);
    }
}

static void menu_buscar_compromisso()
{
    puts("menu buscar compromisso");
}

static void menu_deletar_compromisso()
{
    puts("menu deletar compromisso");
}

static void menu_adicionar_tarefa()
{
    if (qntdTarefas >= MAX_VETOR) {
        printf("\nA agenda de tarefas está cheia.\n");
        system("cls");
        return;
    }

    Tarefa tarefa;

    printf("\n--- Cadastro de Tarefa ---\n");

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o titulo da tarefa: ");

            if (ler_linha(tarefa.titulo, MAX_TITULO) == 0) {
                puts("\nO campo de titulo nao pode estar vazio!");
                continue;
            }
            pronto = true;
        }
    }
    
    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o numero da prioridade da tarefa (Menor numero = Maior prioridade): ");

            if (ler_numero(&tarefa.prioridade) == 0) {
                puts("\nNumero invalido!");
                continue;
            }
            pronto = true;
        }
    }

    {
        bool pronto = false;
        while (!pronto)
        {
            printf("\nDigite o status da tarefa (0 = Pendente // 1 = Concluida): ");

            if (ler_numero(&tarefa.status) == 0 || tarefa.status > 1) {
                puts("\nNumero invalido!");
                continue;
            }
            pronto = true;
        }
    }
    printf("\n");

    tarefas[qntdTarefas++] = tarefa;

    system("cls");
}

static void menu_listar_tarefa()
{
    printf("\n--- Lista de Tarefas ---\n");

    if (qntdTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n\n");
        return;
    }

    for (int i = 0; i < qntdTarefas; i++) {
        printf("\n[Tarefa %d]\n", i + 1);
        printf("Titulo: %s\n", tarefas[i].titulo);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Status: %s\n\n", tarefas[i].status == 0 ? "PENDENTE" : "CONCLUIDA");
    }
}

static void menu_buscar_tarefa()
{
    puts("menu buscar tarefa");
}

static void menu_deletar_tarefa()
{
    puts("menu deletar tarefa");
}
