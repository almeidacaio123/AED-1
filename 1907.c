#include <stdio.h>

typedef struct {
    int x, y;
} No;

char grid[1030][1030];
No pilha[1100000];
int topo = 0;
int N, M;

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int cliques = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(grid[i][j] == '.') {
                cliques++;
                
                grid[i][j] = 'o';
                pilha[topo].x = i;
                pilha[topo].y = j;
                topo++;

                while(topo > 0) {
                    topo--;
                    int cx = pilha[topo].x;
                    int cy = pilha[topo].y;

                    for(int k = 0; k < 4; k++) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];

                        if(nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.') {
                            grid[nx][ny] = 'o';
                            pilha[topo].x = nx;
                            pilha[topo].y = ny;
                            topo++;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
