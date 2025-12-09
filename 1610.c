/**
 * 1610.c - Dudu Faz Serviço
 * Detecção de Ciclo em Grafo Direcionado (DFS)
 */
#include <stdio.h>
#include <stdlib.h>

// Estrutura para Lista de Adjacência
typedef struct No {
    int destino;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;
} ListaAdj;

// Estados do DFS
#define BRANCO 0
#define CINZA  1
#define PRETO  2

// Variáveis globais para simplificar a recursão
int visitado[10005];
ListaAdj grafo[10005];
int encontrou_ciclo;

void adicionar_aresta(int u, int v) {
    No *novo = (No*) malloc(sizeof(No));
    novo->destino = v;
    novo->prox = grafo[u].cabeca;
    grafo[u].cabeca = novo;
}

void limpar_grafo(int N) {
    for (int i = 1; i <= N; i++) {
        No *atual = grafo[i].cabeca;
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        grafo[i].cabeca = NULL;
        visitado[i] = BRANCO;
    }
}

void dfs(int u) {
    visitado[u] = CINZA; // Marcamos como "sendo visitado"
    
    No *atual = grafo[u].cabeca;
    while (atual != NULL) {
        int v = atual->destino;
        
        if (visitado[v] == CINZA) {
            encontrou_ciclo = 1;
            return; // Ciclo detectado
        }
        
        if (visitado[v] == BRANCO) {
            dfs(v);
            if (encontrou_ciclo) return;
        }
        
        atual = atual->prox;
    }
    
    visitado[u] = PRETO; // Finalizamos o vértice
}

int main() {
    int T, N, M;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &N, &M);
        
        // Inicialização
        for(int i=1; i<=N; i++) grafo[i].cabeca = NULL; // Garante NULL antes de limpar/usar
        limpar_grafo(N); 
        
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionar_aresta(A, B);
        }
        
        encontrou_ciclo = 0;
        
        // Pode ser um grafo desconexo, então testamos todos
        for (int i = 1; i <= N; i++) {
            if (visitado[i] == BRANCO) {
                dfs(i);
                if (encontrou_ciclo) break;
            }
        }
        
        if (encontrou_ciclo) printf("SIM\n");
        else printf("NAO\n");
    }
    return 0;
}
