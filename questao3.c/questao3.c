#include <stdio.h>
#include <string.h>

#define TAM 100

// Estrutura da conta
struct Conta {
    int numeroConta;
    char nome[50];
    char cpf[20];
    char telefone[20];
    float saldo;
};

// (a) Função de busca
int buscarConta(struct Conta contas[], int total, int numeroConta) {

    int i;

    // Cadastro vazio
    if(total == 0) {
        return -1;
    }

    // Procura a conta
    for(i = 0; i < total; i++) {

        if(contas[i].numeroConta == numeroConta) {
            return i;
        }
    }

    // Conta não encontrada
    return -2;
}

// (b) Cadastro de nova conta
void cadastrarConta(struct Conta contas[], int *total) {

    int numero;
    int posicao;

    // Verifica limite
    if(*total >= TAM) {
        printf("\nCadastro cheio!\n");
        return;
    }

    printf("\nNumero da conta: ");
    scanf("%d", &numero);

    // Busca a conta
    posicao = buscarConta(contas, *total, numero);

    // Conta já existe
    if(posicao >= 0) {

        printf("\nConta ja cadastrada!\n");
    }
    else {

        contas[*total].numeroConta = numero;

        printf("Nome do cliente: ");
        scanf(" %[^\n]", contas[*total].nome);

        printf("CPF: ");
        scanf(" %[^\n]", contas[*total].cpf);

        printf("Telefone: ");
        scanf(" %[^\n]", contas[*total].telefone);

        printf("Saldo: ");
        scanf("%f", &contas[*total].saldo);

        (*total)++;

        printf("\nConta cadastrada com sucesso!\n");
    }
}

// (c) Consultar saldo
void consultarSaldo(struct Conta contas[],
                    int total,
                    int numeroConta) {

    int posicao;

    posicao = buscarConta(contas, total, numeroConta);

    if(posicao >= 0) {

        printf("\nSaldo: R$ %.2f\n",
               contas[posicao].saldo);
    }
    else {

        printf("\nConta nao cadastrada!\n");
    }
}

// (d) Depósito
void depositar(struct Conta contas[],
               int total,
               int numeroConta) {

    int posicao;
    float valor;

    posicao = buscarConta(contas, total, numeroConta);

    if(posicao >= 0) {

        printf("\nValor do deposito: ");
        scanf("%f", &valor);

        contas[posicao].saldo += valor;

        printf("\nDeposito realizado!\n");
    }
    else {

        printf("\nConta nao cadastrada!\n");
    }
}

// (e) Saque
void sacar(struct Conta contas[],
           int total,
           int numeroConta) {

    int posicao;
    float valor;

    posicao = buscarConta(contas, total, numeroConta);

    if(posicao == -2 || posicao == -1) {

        printf("\nConta nao cadastrada!\n");
    }
    else {

        printf("\nValor do saque: ");
        scanf("%f", &valor);

        if(valor <= contas[posicao].saldo) {

            contas[posicao].saldo -= valor;

            printf("\nSaque realizado!\n");
        }
        else {

            printf("\nSaldo insuficiente!\n");
        }
    }
}

// (f) Exibir contas
void exibirContas(struct Conta contas[],
                  int total) {

    int i;

    if(total == 0) {

        printf("\nNenhuma conta cadastrada!\n");
    }
    else {

        printf("\nCONTAS CADASTRADAS\n");

        for(i = 0; i < total; i++) {

            printf("\nNumero da conta: %d",
                   contas[i].numeroConta);

            printf("\nNome: %s",
                   contas[i].nome);

            printf("\nTelefone: %s\n",
                   contas[i].telefone);
        }
    }
}

// Programa principal
int main() {

    struct Conta contaCorrente[TAM];
    struct Conta contaPoupanca[TAM];

    int totalCorrente = 0;
    int totalPoupanca = 0;

    int opcao;
    int tipoConta;
    int numeroConta;

    do {

        printf("\n===== BANCO DINHEIRO CERTO =====\n");

        printf("\n1 - Cadastrar conta");
        printf("\n2 - Consultar saldo");
        printf("\n3 - Deposito");
        printf("\n4 - Saque");
        printf("\n5 - Exibir contas");
        printf("\n0 - Sair");

        printf("\n\nOpcao: ");
        scanf("%d", &opcao);

        if(opcao != 0) {

            printf("\n1 - Conta Corrente");
            printf("\n2 - Conta Poupanca");

            printf("\nTipo da conta: ");
            scanf("%d", &tipoConta);
        }

        switch(opcao) {

            case 1:

                if(tipoConta == 1) {

                    cadastrarConta(contaCorrente,
                                    &totalCorrente);
                }
                else {

                    cadastrarConta(contaPoupanca,
                                    &totalPoupanca);
                }

                break;

            case 2:

                printf("\nNumero da conta: ");
                scanf("%d", &numeroConta);

                if(tipoConta == 1) {

                    consultarSaldo(contaCorrente,
                                    totalCorrente,
                                    numeroConta);
                }
                else {

                    consultarSaldo(contaPoupanca,
                                    totalPoupanca,
                                    numeroConta);
                }

                break;

            case 3:

                printf("\nNumero da conta: ");
                scanf("%d", &numeroConta);

                if(tipoConta == 1) {

                    depositar(contaCorrente,
                              totalCorrente,
                              numeroConta);
                }
                else {

                    depositar(contaPoupanca,
                              totalPoupanca,
                              numeroConta);
                }

                break;

            case 4:

                printf("\nNumero da conta: ");
                scanf("%d", &numeroConta);

                if(tipoConta == 1) {

                    sacar(contaCorrente,
                           totalCorrente,
                           numeroConta);
                }
                else {

                    sacar(contaPoupanca,
                           totalPoupanca,
                           numeroConta);
                }

                break;

            case 5:

                if(tipoConta == 1) {

                    exibirContas(contaCorrente,
                                 totalCorrente);
                }
                else {

                    exibirContas(contaPoupanca,
                                 totalPoupanca);
                }

                break;

            case 0:

                printf("\nPrograma encerrado!\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}