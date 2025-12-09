#include <stdio.h>
#include <limits.h>

#define MAX_N 255
#define INF 100000000

int main() {
    int N, M, C, K;
    int adj[MAX_N][MAX_N];
    int dist[MAX_N];
    int visited[MAX_N];

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        
        // Inicialização do grafo e distâncias
        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            visited[i] = 0;
            for (int j = 0; j < N; j++) {
                adj[i][j] = INF;
            }
        }

        // Leitura e transformação das arestas
        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            // Verifica aresta u -> v
            // Permitido se u está na zona livre (>= C) 
            // OU se u está na rota e v é o próximo (v == u + 1)
            if (u >= C) {
                if (p < adj[u][v]) adj[u][v] = p;
            } else {
                if (v == u + 1) {
                    if (p < adj[u][v]) adj[u][v] = p;
                }
            }

            // Verifica aresta v -> u (mesma lógica inversa)
            if (v >= C) {
                if (p < adj[v][u]) adj[v][u] = p;
            } else {
                if (u == v + 1) {
                    if (p < adj[v][u]) adj[v][u] = p;
                }
            }
        }

        // Dijkstra
        dist[K] = 0;

        for (int i = 0; i < N; i++) {
            int u = -1;
            int min_dist = INF;

            // Encontrar o nó não visitado com menor distância
            for (int j = 0; j < N; j++) {
                if (!visited[j] && dist[j] < min_dist) {
                    min_dist = dist[j];
                    u = j;
                }
            }

            if (u == -1 || min_dist == INF) break;
            
            visited[u] = 1;

            // Relaxamento dos vizinhos
            for (int v = 0; v < N; v++) {
                if (adj[u][v] != INF && !visited[v]) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }

        printf("%d\n", dist[C-1]);
    }

    return 0;
}
