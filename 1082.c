#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[30][30];
int visited[30];
int V, E;
int component_nodes[30];
int count_nodes;

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void dfs(int u) {
    visited[u] = 1;
    component_nodes[count_nodes++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N, case_num = 1;
    if(scanf("%d", &N));

    while (N--) {
        if(scanf("%d %d", &V, &E));
        
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < E; i++) {
            char u, v;
            if(scanf(" %c %c", &u, &v));
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1;
        }

        printf("Case #%d:\n", case_num++);
        int num_components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                num_components++;
                count_nodes = 0;
                dfs(i);
                
                qsort(component_nodes, count_nodes, sizeof(int), compare);

                for (int j = 0; j < count_nodes; j++) {
                    printf("%c,", component_nodes[j] + 'a');
                }
                printf("\n");
            }
        }
        printf("%d connected components\n\n", num_components);
    }
    return 0;
}
