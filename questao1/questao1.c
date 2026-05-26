#include <stdio.h>
#include <string.h>

#define TAM 26

// Estrutura dos estados
struct Estado {
    char nome[30];
    int veiculos;
    int acidentes;
};

// (a) Cadastro dos estados
void cadastrarEstados(struct Estado estados[]) {

    int i;

    for(i = 0; i < TAM; i++) {

        printf("\nEstado %d\n", i + 1);

        printf("Nome do estado: ");
        scanf(" %[^\n]", estados[i].nome);

        printf("Numero de veiculos: ");
        scanf("%d", &estados[i].veiculos);

        printf("Numero de acidentes: ");
        scanf("%d", &estados[i].acidentes);
    }
}

// (b) Maior e menor numero de acidentes
void maiorMenorAcidentes(struct Estado estados[],
                         int *maior,
                         int *menor) {

    int i;

    *maior = 0;
    *menor = 0;

    for(i = 1; i < TAM; i++) {

        if(estados[i].acidentes > estados[*maior].acidentes) {
            *maior = i;
        }

        if(estados[i].acidentes < estados[*menor].acidentes) {
            *menor = i;
        }
    }
}

// (c) Percentual de acidentes
float percentualAcidentes(struct Estado estados[],
                          int posicao) {

    float percentual;

    percentual =
    ((float) estados[posicao].acidentes /
     estados[posicao].veiculos) * 100;

    return percentual;
}

// (d) Média de acidentes do país
float mediaAcidentes(struct Estado estados[]) {

    int i;
    int soma = 0;

    for(i = 0; i < TAM; i++) {
        soma += estados[i].acidentes;
    }

    return (float) soma / TAM;
}

// (e) Estados acima da média
void acimaDaMedia(struct Estado estados[],
                  float media) {

    int i;

    printf("\nEstados acima da media:\n");

    for(i = 0; i < TAM; i++) {

        if(estados[i].acidentes > media) {
            printf("%s\n", estados[i].nome);
        }
    }
}

// Programa principal
int main() {

    struct Estado estados[TAM];

    int maior, menor;
    int i;

    float media;

    // Cadastro
    cadastrarEstados(estados);

    // Maior e menor número de acidentes
    maiorMenorAcidentes(estados, &maior, &menor);

    printf("\nMaior numero de acidentes:\n");
    printf("Estado: %s\n", estados[maior].nome);
    printf("Acidentes: %d\n", estados[maior].acidentes);

    printf("\nMenor numero de acidentes:\n");
    printf("Estado: %s\n", estados[menor].nome);
    printf("Acidentes: %d\n", estados[menor].acidentes);

    // Percentual de acidentes
    printf("\nPercentual de acidentes por estado:\n");

    for(i = 0; i < TAM; i++) {

        printf("%s: %.2f%%\n",
               estados[i].nome,
               percentualAcidentes(estados, i));
    }

    // Média nacional
    media = mediaAcidentes(estados);

    printf("\nMedia de acidentes do pais: %.2f\n", media);

    // Estados acima da média
    acimaDaMedia(estados, media);

    return 0;
}