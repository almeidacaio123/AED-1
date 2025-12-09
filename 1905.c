#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Para memset

int grid[5][5];
bool visited[5][5];
bool winner;

// Vetores de direção: baixo, cima, direita, esquerda
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    // Verificações de limites e paredes
    if (x < 0 || y < 0 || x >= 5 || y >= 5) return;
    if (grid[x][y] == 1 || visited[x][y]) return;
    
    visited[x][y] = true;
    
    // Chegou no destino (4,4)
    if (x == 4 && y == 4) {
        winner = true;
        return;
    }
    
    // Tenta ir para as 4 direções
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        // Leitura da matriz
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                scanf("%d", &grid[i][j]);
                visited[i][j] = false; // Zera visitados
            }
        }
            
        winner = false;
        dfs(0, 0);
        
        if(winner) printf("COPS\n");
        else printf("ROBBERS\n");
    }
    return 0;
}
