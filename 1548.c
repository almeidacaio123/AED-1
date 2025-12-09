#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)b - *(int*)a; // Ordem decrescente
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        
        int notas_originais[M];
        int notas_ordenadas[M];
        
        // Lê as notas na ordem de chegada
        for (int j = 0; j < M; j++) {
            scanf("%d", &notas_originais[j]);
            notas_ordenadas[j] = notas_originais[j];
        }
        
        // Ordena as notas em ordem decrescente
        qsort(notas_ordenadas, M, sizeof(int), compare);
        
        // Conta quantos alunos permanecem nas mesmas posições
        int count = 0;
        for (int j = 0; j < M; j++) {
            if (notas_originais[j] == notas_ordenadas[j]) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
