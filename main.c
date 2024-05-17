#include <stdio.h>
#include "funcoes.h"

#define MAX_CLIENTES 1000

int main() {
    Cliente clientes[MAX_CLIENTES];
    int num_clientes = 0;
    int opcao;

    do {
        printf("1. Novo cliente\n");
        printf("2. Apaga cliente\n");
        printf("3. Listar clientes\n");
        printf("4. Débito\n");
        printf("5. Depósito\n");
        printf("6. Extrato\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                novo_cliente(clientes, &num_clientes);
                break;
            case 2:
                apaga_cliente(clientes, &num_clientes);
                break;
            case 3:
                listar_clientes(clientes, num_clientes);
                break;
            case 4:
                debito(clientes, num_clientes);
                break;
            case 5:
                deposito(clientes, num_clientes);
                break;
            case 6:
                extrato(clientes, num_clientes);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}