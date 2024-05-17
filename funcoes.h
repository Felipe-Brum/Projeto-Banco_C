#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_OPERACOES 100
#define MAX_CLIENTES 1000

#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo[20];
    double valor;
} Operacao;

typedef struct {
    char nome[50];
    char cpf[11];
    int tipo_conta;
    double saldo;
    char senha[20];
    Operacao operacoes[MAX_OPERACOES];
    int num_operacoes;
} Cliente;

void novo_cliente(Cliente clientes[], int *num_clientes);

#endif