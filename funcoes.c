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

void deposito(Cliente clientes[], int num_clientes) {
    char cpf[11];
    double valor;
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &valor);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clientes[i].saldo += valor;
            strcpy(clientes[i].operacoes[clientes[i].num_operacoes].tipo, "Deposito");
            clientes[i].operacoes[clientes[i].num_operacoes].valor = valor;
            clientes[i].num_operacoes++;
            printf("Depósito realizado com sucesso!\n");
            return;
        }
    }

    printf("CPF não encontrado!\n");
}

void extrato(Cliente clientes[], int num_clientes) {
    char cpf[11];
    char senha[20];
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            char filename[64];
            sprintf(filename, "extrato_%s.txt", cpf);
            FILE *fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Erro ao criar o arquivo de extrato!\n");
                return;
            }

            fprintf(fp, "Extrato para o cliente %s:\n", clientes[i].nome);
            int start_index = (clientes[i].num_operacoes > 100) ? (clientes[i].num_operacoes - 100) : 0;
            for (int j = start_index; j < clientes[i].num_operacoes; j++) {
                fprintf(fp, "%s: %.2lf\n", clientes[i].operacoes[j].tipo, clientes[i].operacoes[j].valor);
            }
            fclose(fp);
            printf("Extrato gerado com sucesso!\n");
            return;
        }
    }

    printf("CPF ou senha incorretos!\n");
}

void transferencia(Cliente clientes[], int num_clientes) {
    char cpf_origem[11], cpf_destino[11];
    char senha[20];
    double valor;
    printf("Digite o CPF da conta de origem: ");
    scanf("%s", cpf_origem);
    printf("Digite a senha: ");
    scanf("%s", senha);
    printf("Digite o CPF da conta de destino: ");
    scanf("%s", cpf_destino);
    printf("Digite o valor a ser transferido: ");
    scanf("%lf", &valor);

    int indice_origem = -1, indice_destino = -1;
    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf_origem) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            indice_origem = i;
        }
        if (strcmp(clientes[i].cpf, cpf_destino) == 0) {
            indice_destino = i;
        }
    }

    if (indice_origem != -1 && indice_destino != -1) {
        double taxa = (clientes[indice_origem].tipo_conta == 1) ? 0.05 : 0.03;
        double saldo_minimo = (clientes[indice_origem].tipo_conta == 1) ? -1000.00 : -5000.00;
        double valor_com_taxa = valor + (valor * taxa);

        if (clientes[indice_origem].saldo - valor_com_taxa >= saldo_minimo) {
            clientes[indice_origem].saldo -= valor_com_taxa;
            strcpy(clientes[indice_origem].operacoes[clientes[indice_origem].num_operacoes].tipo, "Transferencia Enviada");
            clientes[indice_origem].operacoes[clientes[indice_origem].num_operacoes].valor = -valor_com_taxa;
            clientes[indice_origem].num_operacoes++;

            clientes[indice_destino].saldo += valor;
            strcpy(clientes[indice_destino].operacoes[clientes[indice_destino].num_operacoes].tipo, "Transferencia Recebida");
            clientes[indice_destino].operacoes[clientes[indice_destino].num_operacoes].valor = valor;
            clientes[indice_destino].num_operacoes++;

            printf("Transferência realizada com sucesso!\n");
        } else {
            printf("Saldo insuficiente para realizar a transferência!\n");
        }
    } else {
        printf("CPF de origem ou senha incorretos, ou CPF de destino não encontrado!\n");
    }
}