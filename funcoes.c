#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void novo_cliente(Cliente clientes[], int *num_clientes) {
    printf("Digite o nome: ");
    scanf("%s", clientes[*num_clientes].nome);
    printf("Digite o CPF: ");
    scanf("%s", clientes[*num_clientes].cpf);
    printf("Digite o tipo de conta (1 para comum, 2 para plus): ");
    scanf("%d", &clientes[*num_clientes].tipo_conta);
    printf("Digite o saldo inicial: ");
    scanf("%lf", &clientes[*num_clientes].saldo);
    printf("Digite a senha: ");
    scanf("%s", clientes[*num_clientes].senha);
    clientes[*num_clientes].num_operacoes = 0;
    (*num_clientes)++;
}

void apaga_cliente(Cliente clientes[], int *num_clientes) {
    char cpf[11];
    printf("Digite o CPF do cliente a ser apagado: ");
    scanf("%s", cpf);

    for (int i = 0; i < *num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            for (int j = i; j < *num_clientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*num_clientes)--;
            printf("Cliente apagado com sucesso!\n");
            return;
        }
    }

    printf("CPF não encontrado!\n");
}

void listar_clientes(Cliente clientes[], int num_clientes) {
    for (int i = 0; i < num_clientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %s\n", clientes[i].tipo_conta == 1 ? "Comum" : "Plus");
        printf("Saldo: %.2lf\n", clientes[i].saldo);
        printf("Número de operações: %d\n", clientes[i].num_operacoes);
        printf("---------------------------\n");
    }
}

void debito(Cliente clientes[], int num_clientes) {
    char cpf[11];
    char senha[20];
    double valor;
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    printf("Digite a senha: ");
    scanf("%s", senha);
    printf("Digite o valor a ser debitado: ");
    scanf("%lf", &valor);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            double taxa = (clientes[i].tipo_conta == 1) ? 0.05 : 0.03;
            double saldo_minimo = (clientes[i].tipo_conta == 1) ? -1000.00 : -5000.00;
            double valor_com_taxa = valor + (valor * taxa);

            if (clientes[i].saldo - valor_com_taxa >= saldo_minimo) {
                clientes[i].saldo -= valor_com_taxa;
                strcpy(clientes[i].operacoes[clientes[i].num_operacoes].tipo, "Debito");
                clientes[i].operacoes[clientes[i].num_operacoes].valor = -valor_com_taxa;
                clientes[i].num_operacoes++;
                printf("Débito realizado com sucesso!\n");
            } else {
                printf("Saldo insuficiente para realizar o débito!\n");
            }
            return;
        }
    }

    printf("CPF ou senha incorretos!\n");
}