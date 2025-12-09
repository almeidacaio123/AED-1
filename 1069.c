#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char linha[1001];

    scanf("%d", &n);
    
    while (n--) {
        scanf("%s", linha);
        
        int tamanho = strlen(linha);
        int abertos = 0;
        int diamantes = 0;
        
        for (int i = 0; i < tamanho; i++) {
            if (linha[i] == '<') {
                abertos++;
            } else if (linha[i] == '>') {
                if (abertos > 0) {
                    abertos--;
                    diamantes++;
                }
            }
        }
        
        printf("%d\n", diamantes);
    }
    
    return 0;
}
