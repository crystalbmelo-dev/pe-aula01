#include <stdio.h>

#define TAM 30

struct Aluno {
    double nota1;
    double nota2;
    double media;
};

void lerNotas(struct Aluno alunos[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Digite a nota 1: ");
        scanf("%lf", &alunos[i].nota1);
        printf("Digite a nota 2: ");
        scanf("%lf", &alunos[i].nota2);
    }
}

void calcularMedias(struct Aluno alunos[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        alunos[i].media = (alunos[i].nota1 * 2 + alunos[i].nota2 * 3) / 5;
    }
}

double calcularMediaTurma(struct Aluno alunos[]) {
    int i;
    double soma = 0;

    for (i = 0; i < TAM; i++) {
        soma += alunos[i].media;
    }

    return soma / TAM;
}

void imprimirAcimaMedia(struct Aluno alunos[], double mediaTurma) {
    int i;

    printf("\nMedia da turma: %.2lf\n", mediaTurma);
    printf("\nAlunos acima da media da turma:\n");

    for (i = 0; i < TAM; i++) {
        if (alunos[i].media > mediaTurma) {
            printf("\nAluno %d\n", i + 1);
            printf("Nota 1: %.2lf\n", alunos[i].nota1);
            printf("Nota 2: %.2lf\n", alunos[i].nota2);
            printf("Media: %.2lf\n", alunos[i].media);
        }
    }
}

int main() {
    struct Aluno alunos[TAM];
    double mediaTurma;

    lerNotas(alunos);
    calcularMedias(alunos);
    mediaTurma = calcularMediaTurma(alunos);
    imprimirAcimaMedia(alunos, mediaTurma);

    return 0;
}