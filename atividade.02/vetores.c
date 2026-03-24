#include <stdio.h>

#define MAX 50

int main() {
    int vetor[MAX];
    int tamanho = 0;
    int capacidade;

    // Escolher tamanho
    do {
        printf("Digite o tamanho do vetor (3 a 50): ");
        scanf("%d", &capacidade);
    } while (capacidade < 3 || capacidade > 50);

    // Preencher vetor (inserção ordenada)
    int qtd;
    printf("Quantos valores deseja inserir? ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        int valor;
        printf("Digite um valor: ");
        scanf("%d", &valor);

        // Inserir ordenado
        int j = tamanho - 1;
        while (j >= 0 && vetor[j] > valor) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = valor;
        tamanho++;
    }

    // Menu
    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Inserir elemento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Imprimir
            printf("Vetor: ");
            for (int i = 0; i < tamanho; i++) {
                printf("%d ", vetor[i]);
            }
            printf("\n");
        }

        else if (opcao == 2) {
            // Busca simples
            int valor, pos = -1;
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);

            for (int i = 0; i < tamanho; i++) {
                if (vetor[i] == valor) {
                    pos = i;
                    break;
                }
            }

            printf("Posicao: %d\n", pos);
        }

        else if (opcao == 3) {
            // Remover
            int valor, pos = -1;
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);

            // Procurar
            for (int i = 0; i < tamanho; i++) {
                if (vetor[i] == valor) {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                printf("Elemento nao encontrado.\n");
            } else {
                // Deslocar
                for (int i = pos; i < tamanho - 1; i++) {
                    vetor[i] = vetor[i + 1];
                }
                tamanho--;
                printf("Removido com sucesso!\n");
            }
        }

        else if (opcao == 4) {
            // Inserir novo valor ordenado
            if (tamanho >= capacidade) {
                printf("Vetor cheio!\n");
            } else {
                int valor;
                printf("Digite o valor: ");
                scanf("%d", &valor);

                int j = tamanho - 1;
                while (j >= 0 && vetor[j] > valor) {
                    vetor[j + 1] = vetor[j];
                    j--;
                }
                vetor[j + 1] = valor;
                tamanho++;

                printf("Inserido com sucesso!\n");
            }
        }

    } while (opcao != 0);

    return 0;
}