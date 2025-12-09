#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 1000000000

typedef struct Edge {
    int v, w;
    struct Edge *next;
} Edge;

Edge *g[501], *gr[501];
int visited[501], stack[501], top;
int comp[501], scc_count;
Edge *cg[501]; // condensed graph adj list (by SCC id)
int scc_size[501]; // optional, size of each SCC

void add_edge(Edge **G, int u, int v, int w) {
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->v = v; e->w = w; e->next = G[u];
    G[u] = e;
}

void dfs1(int u) {
    visited[u] = 1;
    for (Edge *e = g[u]; e; e = e->next)
        if (!visited[e->v]) dfs1(e->v);
    stack[top++] = u;
}

void dfs2(int u, int c) {
    comp[u] = c;
    scc_size[c]++;
    for (Edge *e = gr[u]; e; e = e->next)
        if (comp[e->v] == -1) dfs2(e->v, c);
}

typedef struct {
    int v, dist;
} Node;

typedef struct {
    Node arr[501];
    int size;
} MinHeap;

void push(MinHeap *h, int v, int dist) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = dist;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p].dist <= h->arr[i].dist) break;
        Node tmp = h->arr[p];
        h->arr[p] = h->arr[i];
        h->arr[i] = tmp;
        i = p;
    }
}

Node pop(MinHeap *h) {
    Node ret = h->arr[0];
    h->size--;
    h->arr[0] = h->arr[h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, small = i;
        if (l < h->size && h->arr[l].dist < h->arr[small].dist) small = l;
        if (r < h->size && h->arr[r].dist < h->arr[small].dist) small = r;
        if (small == i) break;
        Node tmp = h->arr[i];
        h->arr[i] = h->arr[small];
        h->arr[small] = tmp;
        i = small;
    }
    return ret;
}

int dist[501];

int dijkstra(int start, int goal, int scc_total) {
    for (int i = 0; i < scc_total; i++) dist[i] = INF;
    MinHeap h; h.size = 0;

    dist[start] = 0;
    push(&h, start, 0);

    while (h.size > 0) {
        Node x = pop(&h);
        int u = x.v;
        if (x.dist > dist[u]) continue;
        if (u == goal) return dist[u];

        for (Edge *e = cg[u]; e; e = e->next) {
            int v = e->v, nd = dist[u] + e->w;
            if (nd < dist[v]) {
                dist[v] = nd;
                push(&h, v, nd);
            }
        }
    }
    return INF;
}

int main() {
    int N, E;

    while (scanf("%d %d", &N, &E) && (N || E)) {

        // Reset graphs
        for (int i = 1; i <= N; i++) {
            g[i] = gr[i] = NULL;
        }

        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            add_edge(g, X, Y, H);
            add_edge(gr, Y, X, H); // reverse
        }

        // Kosaraju - Pass 1
        memset(visited, 0, sizeof(visited));
        top = 0;
        for (int i = 1; i <= N; i++)
            if (!visited[i]) dfs1(i);

        // Pass 2
        memset(comp, -1, sizeof(comp));
        scc_count = 0;
        memset(scc_size, 0, sizeof(scc_size));

        for (int i = top - 1; i >= 0; i--) {
            int u = stack[i];
            if (comp[u] == -1) {
                dfs2(u, scc_count);
                scc_count++;
            }
        }

        // Build condensed graph
        for (int i = 0; i < scc_count; i++) cg[i] = NULL;

        for (int u = 1; u <= N; u++) {
            for (Edge *e = g[u]; e; e = e->next) {
                int cu = comp[u], cv = comp[e->v];
                if (cu != cv) {
                    add_edge(cg, cu, cv, e->w);
                }
            }
        }

        int K;
        scanf("%d", &K);

        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);
            int co = comp[O], cd = comp[D];

            if (co == cd) {
                printf("0\n");
            } else {
                int ans = dijkstra(co, cd, scc_count);
                if (ans == INF)
                    printf("Nao e possivel entregar a carta\n");
                else
                    printf("%d\n", ans);
            }
        }

        printf("\n");
    }

    return 0;
}
