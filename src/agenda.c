#include "agenda.h"



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
