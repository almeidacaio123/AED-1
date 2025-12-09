#include <stdio.h>
#include <string.h>

#define MAX 50

int adj[MAX][MAX];
int visited[MAX];
int count_edges;

void dfs(int u, int V) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                count_edges++;
                dfs(v, V);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int start, V, A;
        scanf("%d", &start);
        scanf("%d %d", &V, &A);

        // Limpar grafo
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        count_edges = 0;

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        dfs(start, V);

        printf("%d\n", count_edges * 2);
    }
    return 0;
}
