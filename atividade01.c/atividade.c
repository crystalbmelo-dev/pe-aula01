#include <stdio.h>

#define NUM_ALUNOS 30

int main() {
    float nota1[NUM_ALUNOS], nota2[NUM_ALUNOS], media[NUM_ALUNOS];
    float soma_media = 0, media_turma;

    for (int i = 0; i < NUM_ALUNOS; i++) {

        printf("Digite a 1ª nota do aluno %d: ", i + 1);
        scanf("%f", &nota1[i]);

        while (nota1[i] < 0 || nota1[i] > 10) {
            printf("Nota invalida! Digite novamente: ");
            scanf("%f", &nota1[i]);
        }

        printf("Digite a 2ª nota do aluno %d: ", i + 1);
        scanf("%f", &nota2[i]);

        while (nota2[i] < 0 || nota2[i] > 10) {
            printf("Nota invalida! Digite novamente: ");
            scanf("%f", &nota2[i]);
        }

        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5;
        soma_media += media[i];
    }

    media_turma = soma_media / NUM_ALUNOS;

    printf("\nMedia da turma: %.2f\n", media_turma);

    printf("\nAlunos acima da media da turma:\n");

    for (int i = 0; i < NUM_ALUNOS; i++) {
        if (media[i] > media_turma) {
            printf("Aluno %d - Nota1: %.2f  Nota2: %.2f  Media: %.2f\n",
                   i + 1, nota1[i], nota2[i], media[i]);
        }
    }

    return 0;
}