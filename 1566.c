#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    int altura;
    struct Pessoa *esquerda, *direita;
} Pessoa;

Pessoa* novoNo(int altura) {
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    p->altura = altura;
    p->esquerda = p->direita = NULL;
    return p;
}

Pessoa* inserir(Pessoa* raiz, int altura) {
    if (!raiz) return novoNo(altura);
    if (altura < raiz->altura) raiz->esquerda = inserir(raiz->esquerda, altura);
    else raiz->direita = inserir(raiz->direita, altura);
    return raiz;
}

void imprimirEmOrdem(Pessoa* raiz, int *primeiro) {
    if (raiz) {
        imprimirEmOrdem(raiz->esquerda, primeiro);
        if (*primeiro) *primeiro = 0; else printf(" ");
        printf("%d", raiz->altura);
        imprimirEmOrdem(raiz->direita, primeiro);
    }
}

void liberarArvore(Pessoa* raiz) {
    if (raiz) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    int numeroCidades;
    scanf("%d", &numeroCidades);

    while (numeroCidades--) {
        int numeroPessoas, altura;
        scanf("%d", &numeroPessoas);
        Pessoa* cidade = NULL;

        for (int i = 0; i < numeroPessoas; i++) {
            scanf("%d", &altura);
            cidade = inserir(cidade, altura);
        }

        int primeiro = 1;
        imprimirEmOrdem(cidade, &primeiro);
        printf("\n");

        liberarArvore(cidade);
    }
    return 0;
}
