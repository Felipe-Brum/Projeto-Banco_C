#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_OPERACOES 100
#define MAX_CLIENTES 1000

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
void apaga_cliente(Cliente clientes[], int *num_clientes);
void listar_clientes(Cliente clientes[], int num_clientes);
void debito(Cliente clientes[], int num_clientes);
void deposito(Cliente clientes[], int num_clientes);
void extrato(Cliente clientes[], int num_clientes);
void transferencia(Cliente clientes[], int num_clientes);

#endif