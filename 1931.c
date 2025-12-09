#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 2000000000
#define MAX_C 10005

// Estrutura para Lista de Adjacência
typedef struct Node {
    int v, w;
    struct Node *next;
} Node;

Node *adj[MAX_C];

// Estrutura para Heap (Min-Priority Queue)
typedef struct {
    int dist, u, parity;
} HeapNode;

HeapNode heap[MAX_C * 40]; // Tamanho seguro
int heap_size = 0;

void add_edge(int u, int v, int w) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->v = v;
    new_node->w = w;
    new_node->next = adj[u];
    adj[u] = new_node;
}

void push(int d, int u, int p) {
    int i = heap_size++;
    while (i > 0) {
        int p_idx = (i - 1) / 2;
        if (heap[p_idx].dist <= d) break;
        heap[i] = heap[p_idx];
        i = p_idx;
    }
    heap[i] = (HeapNode){d, u, p};
}

HeapNode pop() {
    HeapNode ret = heap[0];
    HeapNode x = heap[--heap_size];
    int i = 0;
    while (i * 2 + 1 < heap_size) {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < heap_size && heap[b].dist < heap[a].dist) a = b;
        if (heap[a].dist >= x.dist) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int dist[MAX_C][2]; // [Cidade][0=Par, 1=Impar]

int main() {
    int C, V;
    scanf("%d %d", &C, &V);

    for (int i = 1; i <= C; i++) {
        adj[i] = NULL;
        dist[i][0] = dist[i][1] = INF;
    }

    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    // Dijkstra
    dist[1][0] = 0; // Começa na cidade 1 com paridade 0 (contador de arestas zerado)
    push(0, 1, 0);

    while (heap_size > 0) {
        HeapNode top = pop();
        int d = top.dist;
        int u = top.u;
        int p = top.parity;

        if (d > dist[u][p]) continue;

        Node *curr = adj[u];
        while (curr != NULL) {
            int v = curr->v;
            int w = curr->w;
            int next_p = 1 - p; // Alterna paridade (0->1, 1->0)

            if (dist[u][p] + w < dist[v][next_p]) {
                dist[v][next_p] = dist[u][p] + w;
                push(dist[v][next_p], v, next_p);
            }
            curr = curr->next;
        }
    }

    // Queremos chegar em C com paridade 0 (número par de arestas)
    if (dist[C][0] == INF) printf("-1\n");
    else printf("%d\n", dist[C][0]);

    return 0;
}
