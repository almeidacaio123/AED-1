#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Implementação manual de busca binária para encontrar a PRIMEIRA ocorrência
int binary_search_first(int *arr, int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continua buscando na esquerda
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int N, Q, case_num = 1;
    
    while (scanf("%d %d", &N, &Q) && (N || Q)) {
        int *marbles = (int*) malloc(N * sizeof(int));
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }
        
        // Ordenação
        qsort(marbles, N, sizeof(int), compare);
        
        printf("CASE# %d:\n", case_num++);
        
        for (int i = 0; i < Q; i++) {
            int query;
            scanf("%d", &query);
            
            int pos = binary_search_first(marbles, N, query);
            
            if (pos != -1) {
                printf("%d found at %d\n", query, pos + 1);
            } else {
                printf("%d not found\n", query);
            }
        }
        
        free(marbles);
    }
    return 0;
}
