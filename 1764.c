/**
 * 1764.c - Itinerário do Papai Noel
 * MST usando Algoritmo de Kruskal (Union-Find)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
} Aresta;

// Estrutura Union-Find
int pai[40005];

// Inicializa cada nó como seu próprio pai
void make_set(int n) {
    for (int i = 0; i < n; i++) pai[i] = i;
}

// Encontra o representante do conjunto (com compressão de caminho)
int find_set(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find_set(pai[x]);
}

// Une dois conjuntos
void union_set(int x, int y) {
    int rootX = find_set(x);
    int rootY = find_set(y);
    if (rootX != rootY) {
        pai[rootX] = rootY;
    }
}

// Comparador para o qsort
int compara(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int main() {
    int M, N;
    
    while (scanf("%d %d", &M, &N) && (M != 0 || N != 0)) {
        Aresta *arestas = (Aresta*) malloc(N * sizeof(Aresta));
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }
        
        // 1. Ordenar arestas pelo peso
        qsort(arestas, N, sizeof(Aresta), compara);
        
        // 2. Union-Find
        make_set(M);
        int custo_total = 0;
        
        for (int i = 0; i < N; i++) {
            if (find_set(arestas[i].u) != find_set(arestas[i].v)) {
                union_set(arestas[i].u, arestas[i].v);
                custo_total += arestas[i].peso;
            }
        }
        
        printf("%d\n", custo_total);
        free(arestas);
    }
    return 0;
}
