/**
 * 1062.c - Trilhos
 * Solução usando Pilha Estática
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1005

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void init(Pilha *p) { p->topo = -1; }

void push(Pilha *p, int v) { p->itens[++(p->topo)] = v; }

void pop(Pilha *p) { if (p->topo >= 0) p->topo--; }

int top(Pilha *p) { return (p->topo >= 0) ? p->itens[p->topo] : -1; }

int main() {
    int N;
    int target[MAX];
    
    while (scanf("%d", &N) && N != 0) {
        while (1) {
            // Lê o primeiro vagão para saber se continua o bloco ou encerra
            scanf("%d", &target[0]);
            if (target[0] == 0) {
                printf("\n");
                break;
            }
            
            // Lê o resto da permutação desejada
            for (int i = 1; i < N; i++) {
                scanf("%d", &target[i]);
            }
            
            Pilha estacao;
            init(&estacao);
            
            int currCoach = 1; // O vagão que está chegando da entrada A (1..N)
            int targetIdx = 0; // Índice do vagão que precisamos despachar agora
            int possible = 1;
            
            while (targetIdx < N) {
                if (currCoach == target[targetIdx]) {
                    // Vagão chegou e já é o que precisamos: entra e sai
                    currCoach++;
                    targetIdx++;
                } else if (top(&estacao) == target[targetIdx]) {
                    // O vagão necessário está no topo da pilha
                    pop(&estacao);
                    targetIdx++;
                } else if (currCoach <= N) {
                    // Não temos o vagão ainda, empilha o atual e tenta o próximo
                    push(&estacao, currCoach);
                    currCoach++;
                } else {
                    // Não tem mais vagões vindo e o topo não serve
                    possible = 0;
                    break;
                }
            }
            
            if (possible) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
