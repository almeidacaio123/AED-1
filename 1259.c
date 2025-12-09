#include <stdio.h>
#include <stdlib.h>

// Função comparadora para o qsort
// Retorna negativo se A deve vir antes de B
// Retorna positivo se A deve vir depois de B
int comparar(const void *a, const void *b) {
    int A = *(int*)a;
    int B = *(int*)b;
    
    int parA = (A % 2 == 0);
    int parB = (B % 2 == 0);
    
    // Caso 1: Um é par e o outro é ímpar
    // O Par deve vir primeiro
    if (parA && !parB) return -1; 
    if (!parA && parB) return 1;
    
    // Caso 2: Ambos são pares
    // Ordenação Crescente (menor menos maior)
    if (parA && parB) return A - B;
    
    // Caso 3: Ambos são ímpares
    // Ordenação Decrescente (maior menos menor)
    if (!parA && !parB) return B - A;
    
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    
    // Alocação dinâmica do vetor
    int *valores = (int*)malloc(N * sizeof(int));
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &valores[i]);
    }
    
    // A mágica acontece aqui: uma única linha resolve tudo
    qsort(valores, N, sizeof(int), comparar);
    
    for(int i = 0; i < N; i++) {
        printf("%d\n", valores[i]);
    }
    
    free(valores);
    return 0;
}
