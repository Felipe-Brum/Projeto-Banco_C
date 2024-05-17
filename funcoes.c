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
    scanf("\n"); // Limpa o buffer
    fgets(clientes[*num_clientes].senha, 20, stdin); // Lê a senha até a nova linha
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

    printf("CPF nao encontrado!\n");
}

void listar_clientes(Cliente clientes[], int num_clientes) {
    for (int i = 0; i < num_clientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %d\n", clientes[i].tipo_conta);
        printf("Saldo: %.2lf\n", clientes[i].saldo);
        printf("Numero de operacoes: %d\n", clientes[i].num_operacoes);
    }
}