#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para garantir a estabilidade da ordenação
typedef struct {
    char palavra[55];
    int posicao_original;
    int tamanho;
} Word;

// Comparador customizado
int comparar(const void *a, const void *b) {
    Word *w1 = (Word*)a;
    Word *w2 = (Word*)b;
    
    // Critério 1: Tamanho (Decrescente -> maior vem antes)
    if (w1->tamanho != w2->tamanho) {
        return w2->tamanho - w1->tamanho;
    }
    
    // Critério 2: Estabilidade (Crescente -> menor índice original vem antes)
    return w1->posicao_original - w2->posicao_original;
}

int main() {
    int N;
    char linha[3000]; // Buffer grande para ler a linha inteira
    
    scanf("%d", &N);
    getchar(); // Limpa o \n do buffer
    
    while(N--) {
        // Lê a linha inteira (incluindo espaços)
        // O scanf("%[^\n]") lê tudo até encontrar uma quebra de linha
        scanf("%[^\n]", linha);
        getchar(); // Limpa o \n
        
        Word palavras[55]; // Array de structs (supondo max 50 palavras por linha)
        int count = 0;
        
        // Tokenização manual (quebrar a string nos espaços)
        char *token = strtok(linha, " ");
        while(token != NULL) {
            strcpy(palavras[count].palavra, token);
            palavras[count].tamanho = strlen(token);
            palavras[count].posicao_original = count;
            count++;
            
            token = strtok(NULL, " ");
        }
        
        // Ordena
        qsort(palavras, count, sizeof(Word), comparar);
        
        // Imprime com espaço entre as palavras, mas não no final
        for(int i = 0; i < count; i++) {
            printf("%s", palavras[i].palavra);
            if (i < count - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
