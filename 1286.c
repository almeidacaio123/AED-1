#include <stdio.h>
#include <string.h>

// Função auxiliar para máximo
int max(int a, int b) {
    return (a > b) ? a : b;
}

int tempo[25];
int pizzas[25];
int dp[25][35]; // dp[item][capacidade]

int main() {
    int N, P; // N = pedidos, P = limite de pizzas
    
    while(scanf("%d", &N) && N != 0) {
        scanf("%d", &P);
        
        for(int i = 0; i < N; i++) {
            scanf("%d %d", &tempo[i], &pizzas[i]);
        }
        
        // Inicializa a tabela DP com 0
        // dp[i][w] = lucro máximo usando itens até i com capacidade w
        memset(dp, 0, sizeof(dp));
        
        // Construção da tabela DP
        // i: índice do pedido atual (1 até N)
        // w: capacidade atual da mochila (0 até P)
        for(int i = 0; i <= N; i++) {
            for(int w = 0; w <= P; w++) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0;
                } else {
                    int peso_item = pizzas[i-1];
                    int valor_item = tempo[i-1];
                    
                    if (peso_item <= w) {
                        // Escolhe o máximo entre: pegar o item ou não pegar
                        dp[i][w] = max(
                            valor_item + dp[i-1][w - peso_item], // Pegar
                            dp[i-1][w]                           // Não pegar
                        );
                    } else {
                        // Não cabe, repete o valor anterior
                        dp[i][w] = dp[i-1][w];
                    }
                }
            }
        }
        
        printf("%d min.\n", dp[N][P]);
    }
    return 0;
}
