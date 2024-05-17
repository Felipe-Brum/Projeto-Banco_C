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
    scanf("\n");
    fgets(clientes[*num_clientes].senha, 20, stdin);
    clientes[*num_clientes].num_operacoes = 0;
    (*num_clientes)++;
}
