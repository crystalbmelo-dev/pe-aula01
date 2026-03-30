#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 3

void preencherMatrizAleatorio(int m[][COL], int lin, int col);
void imprimirMatriz(int m[][COL], int lin, int col);
void matSoma(int m[][COL], int n[][COL], int soma[][COL]);

int main() {
    int m[LIN][COL];
    int n[LIN][COL];
    int soma[LIN][COL];
    srand(2);
    preencherMatrizAleatorio(m, LIN, COL);
    preencherMatrizAleatorio(n, LIN, COL);

    matSoma(m, n, soma);
    printf("Matriz M:\n");
    imprimirMatriz(m, LIN, COL);
    printf("Matriz N:\n");
    imprimirMatriz(n, LIN, COL);
    printf("Matriz soma:\n");
    imprimirMatriz(soma, LIN, COL);
    return 0;
}

// 1 Crie uma função que recebe 3 matrizes como parâmetro: MatA, MatB 
// e MatSoma, onde cada elemento da MatSoma é a soma dos elementos 
// correspondentes das matrizes MatA e MatB.

void preencherMatrizAleatorio(int m[][COL], int lin, int col){
    for (int i= 0; i < lin; i+=1) {
        for (int j= 0; j < col; j+=1) {
            m[i][j]= rand() % 100 + 1;
        }
    }
}

void matSoma(int m[][COL], int n[][COL], int soma[][COL]){
    for (int i= 0; i < LIN; i+=1) {
        for (int j= 0; j < COL; j+=1) {
            soma[i][j]= m[i][j] + n[i][j];
        }
    }
}

void imprimirMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("%3d\t", m[i][j]);
        }
        printf("\n");
    }
}
