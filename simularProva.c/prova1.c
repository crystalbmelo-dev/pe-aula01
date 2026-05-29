#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria{
    int codigo;
    char nome[50];
};

struct Produto{
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; 
    int preco; 
};

void lerStr(char str[], int tamMax);
void cadastrarCategoria(struct Categoria v[], int *qtd);
void imprimirCategorias(struct Categoria v[], int qtd);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);

int main(){

    struct Categoria categorias[TAM];
    int qtdCategorias = 0;

    struct Produto produtos[TAM];
    int qtdProdutos = 0;

    int escolha;
    char busca[256];

    while(1){

        printf("\n------ SISTEMA DE PRODUTOS ------\n");
        printf("1 - Inserir categoria\n");
        printf("2 - Listar categorias\n");
        printf("3 - Listar produtos\n");
        printf("4 - Ordenar por descricao\n");
        printf("5 - Pesquisar produto (busca binaria)\n");
        printf("0 - Encerrar\n");

        printf("Opcao: ");
        scanf("%d", &escolha);
        getchar();

        if(escolha == 0){
            printf("\nEncerrando sistema...\n");
            break;
        }

        if(escolha == 1){
            cadastrarCategoria(categorias, &qtdCategorias);
        }
        else if(escolha == 2){
            imprimirCategorias(categorias, qtdCategorias);
        }
        else if(escolha == 3){
            imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);
        }
        else if(escolha == 4){
            selectionSortPorDescricao(produtos, qtdProdutos);
            printf("Lista ordenada com sucesso.\n");
        }
        else if(escolha == 5){
            printf("\nInforme a descricao para busca: ");
            lerStr(busca, 256);
            buscaBinariaPorDescricao(produtos, qtdProdutos, busca);
        }
        else{
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}

void lerStr(char str[], int tamMax){

    fgets(str, tamMax, stdin);

    int tam = strlen(str);

    if(tam > 0 && str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}

// QUESTÃO 1
void cadastrarCategoria(struct Categoria v[], int *qtd){

    if(*qtd >= TAM){
        printf("Nao e possivel cadastrar mais categorias.\n");
        return;
    }

    int novoCodigo;

    printf("Digite o codigo da categoria: ");
    scanf("%d", &novoCodigo);
    getchar();

    for(int i = 0; i < *qtd; i++){

        if(v[i].codigo == novoCodigo){
            printf("Codigo ja existente.\n");
            return;
        }
    }

    v[*qtd].codigo = novoCodigo;

    printf("Digite o nome da categoria: ");
    lerStr(v[*qtd].nome, 50);

    (*qtd)++;
}

// QUESTÃO 2
void imprimirCategorias(struct Categoria v[], int qtd){

    printf("Categorias cadastradas:\n");

    for(int i = 0; i < qtd; i++){

        printf("Codigo: %d\n", v[i].codigo);
        printf("Nome: %s\n", v[i].nome);
        printf("\n");
    }
}

// QUESTÃO 3
void imprimirProdutos(struct Produto vp[], int qtdProdutos,
                      struct Categoria vc[], int qtdCategorias){

    printf("Lista de produtos:\n");

    for(int i = 0; i < qtdProdutos; i++){

        char nomeCategoria[50];

        strcpy(nomeCategoria, "Categoria nao encontrada");

        for(int j = 0; j < qtdCategorias; j++){

            if(vc[j].codigo == vp[i].categoria){

                strcpy(nomeCategoria, vc[j].nome);
                break;
            }
        }

        double precoReal = vp[i].preco / 100.0;

        printf("Codigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);
        printf("Categoria: %s\n", nomeCategoria);
        printf("Preco: R$ %.2f\n", precoReal);

        printf("\n");
    }
}

// QUESTÃO 4
void selectionSortPorDescricao(struct Produto v[], int qtd){

    int i, j, menor;

    struct Produto aux;

    for(i = 0; i < qtd - 1; i++){

        menor = i;

        for(j = i + 1; j < qtd; j++){

            if(strcmp(v[j].descricao, v[menor].descricao) < 0){

                menor = j;
            }
        }

        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

// QUESTÃO 5
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x){

    int inicio = 0;
    int fim = qtd - 1;
    int meio;
    int cmp;

    while(inicio <= fim){

        meio = (inicio + fim) / 2;

        cmp = strcmp(v[meio].descricao, x);

        if(cmp == 0){

            printf("Produto encontrado!\n");

            printf("Codigo: %d\n", v[meio].codigo);
            printf("Titulo: %s\n", v[meio].titulo);
            printf("Descricao: %s\n", v[meio].descricao);

            return;
        }

        else if(cmp < 0){

            inicio = meio + 1;
        }

        else{

            fim = meio - 1;
        }
    }

    printf("Produto nao encontrado.\n");
}