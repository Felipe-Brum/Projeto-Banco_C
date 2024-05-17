# Sistema Bancário

Este é um sistema bancário simples implementado em C, que permite gerenciar contas de clientes. O sistema suporta dois tipos de conta: Comum e Plus, e oferece funcionalidades para criar novos clientes, apagar clientes, listar clientes, realizar débitos e depósitos, gerar extratos, e transferir dinheiro entre contas.

## Funcionalidades

1. *Novo cliente*: Cadastra um novo cliente no sistema.
2. *Apaga cliente*: Remove um cliente do sistema pelo CPF.
3. *Listar clientes*: Lista todos os clientes cadastrados.
4. *Débito*: Realiza um débito na conta do cliente.
5. *Depósito*: Realiza um depósito na conta do cliente.
6. *Extrato*: Gera um arquivo txt com o extrato das últimas 100 operações do cliente.
7. *Transferência Entre Contas*: Transfere um valor de uma conta de origem para uma conta de destino.
0. *Sair*: Sai do sistema e salva todos os dados.

## Tipos de Conta

- *Comum*:
  - Cobra taxa de 5% a cada débito realizado.
  - Permite um saldo negativo de até R$ 1.000,00.

- *Plus*:
  - Cobra taxa de 3% a cada débito realizado.
  - Permite um saldo negativo de até R$ 5.000,00.

## Estrutura do Projeto

O projeto está estruturado em três arquivos principais:

- funcoes.h: Contém as definições das estruturas e declarações das funções.
- funcoes.c: Implementa todas as funções declaradas em funcoes.h.
- main.c: Contém a função main e gerencia o loop principal do sistema.

## Compilação e Execução

### Requisitos

- Compilador C (gcc, por exemplo)

### Passos

1. Clone o repositório para sua máquina local.
    bash
    git clone https://github.com/usuario/repositorio.git
    cd repositorio
    

2. Compile o código.
    bash
    gcc main.c funcoes.c -o sistema_bancario
    

3. Execute o programa.
    bash
    ./sistema_bancario
    

## Uso

Ao executar o programa, você verá um menu com as opções disponíveis. Digite o número correspondente à operação que deseja realizar e siga as instruções.

## Salvar e Carregar Dados

O sistema salva automaticamente os dados dos clientes em um arquivo binário (dados.bin) ao sair, e carrega os dados do mesmo arquivo ao iniciar. Isso garante que as informações não sejam perdidas entre as execuções.

## Desenvolvimento

Este projeto foi desenvolvido seguindo boas práticas de versionamento com Git. Cada funcionalidade foi implementada em uma branch separada e mesclada na branch principal (main) após a revisão. As mensagens de commit são claras e descritivas, facilitando o entendimento das mudanças realizadas ao longo do desenvolvimento.