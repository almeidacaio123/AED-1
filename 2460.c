#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

int main() {
    int N, M;
    int fila[MAX];
    int saiu[100001] = {0};
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }
    
    scanf("%d", &M);
  
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        saiu[id] = 1; 
    }
  
    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");
    
    return 0;
}
