#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[200005];

int find_set(int i) {
    if (i == parent[i]) return i;
    return parent[i] = find_set(parent[i]);
}

void union_set(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) && (m || n)) {
        Edge *edges = (Edge*) malloc(n * sizeof(Edge));
        int total_cost = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total_cost += edges[i].w;
        }

        // Kruskal
        qsort(edges, n, sizeof(Edge), compare);
        for (int i = 0; i < m; i++) parent[i] = i;

        int mst_cost = 0;
        int edges_count = 0;

        for (int i = 0; i < n; i++) {
            if (find_set(edges[i].u) != find_set(edges[i].v)) {
                union_set(edges[i].u, edges[i].v);
                mst_cost += edges[i].w;
                edges_count++;
            }
        }

        printf("%d\n", total_cost - mst_cost);
        free(edges);
    }
    return 0;
}
