#include <stdio.h>
#include <stdbool.h>

// Estruturas globais simples para evitar alocação dinâmica complexa na prova
int pilha[1005], topo;
int fila[1005], inicio_fila, fim_fila;
int heap[1005], tamanho_heap;

// Funções de Heap (Max-Heap)
void push_heap(int v) {
    heap[++tamanho_heap] = v;
    int i = tamanho_heap;
    while (i > 1) {
        if (heap[i] > heap[i/2]) {
            int temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i /= 2;
        } else {
            break;
        }
    }
}

int pop_heap() {
    int ret = heap[1];
    heap[1] = heap[tamanho_heap--];
    int i = 1;
    while (i * 2 <= tamanho_heap) {
        int filho = i * 2;
        if (filho + 1 <= tamanho_heap && heap[filho+1] > heap[filho]) {
            filho++;
        }
        if (heap[i] < heap[filho]) {
            int temp = heap[i];
            heap[i] = heap[filho];
            heap[filho] = temp;
            i = filho;
        } else {
            break;
        }
    }
    return ret;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        bool eh_pilha = true, eh_fila = true, eh_pq = true;
        
        // Reiniciar estruturas
        topo = 0;
        inicio_fila = 0; fim_fila = 0;
        tamanho_heap = 0;
        
        for (int i = 0; i < n; i++) {
            int tipo, x;
            scanf("%d %d", &tipo, &x);
            
            if (tipo == 1) { // Inserir
                if (eh_pilha) pilha[topo++] = x;
                if (eh_fila) fila[fim_fila++] = x;
                if (eh_pq) push_heap(x);
            } else { // Remover e verificar
                if (eh_pilha) {
                    if (topo == 0 || pilha[--topo] != x) eh_pilha = false;
                }
                if (eh_fila) {
                    if (inicio_fila == fim_fila || fila[inicio_fila++] != x) eh_fila = false;
                }
                if (eh_pq) {
                    if (tamanho_heap == 0 || pop_heap() != x) eh_pq = false;
                }
            }
        }
        
        if (eh_pilha && !eh_fila && !eh_pq) printf("stack\n");
        else if (!eh_pilha && eh_fila && !eh_pq) printf("queue\n");
        else if (!eh_pilha && !eh_fila && eh_pq) printf("priority queue\n");
        else if (!eh_pilha && !eh_fila && !eh_pq) printf("impossible\n");
        else printf("not sure\n");
    }
    return 0;
}
