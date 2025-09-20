#include <stdio.h>

int validaSudoku(int grid[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        int vistos[10] = {0};
        for (j = 0; j < 9; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || vistos[num]) {
                return 0; 
            }
            vistos[num] = 1;
        }
    }

    // Verifica as colunas
    for (j = 0; j < 9; j++) {
        int vistos[10] = {0};
        for (i = 0; i < 9; i++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || vistos[num]) {
                return 0;
            }
            vistos[num] = 1;
        }
    }

    // Verifica as regiões 3x3
    for (int bloco_linha = 0; bloco_linha < 9; bloco_linha += 3) {
        for (int bloco_coluna = 0; bloco_coluna < 9; bloco_coluna += 3) {
            int vistos[10] = {0};
            for (i = bloco_linha; i < bloco_linha + 3; i++) {
                for (j = bloco_coluna; j < bloco_coluna + 3; j++) {
                    int num = grid[i][j];
                    if (num < 1 || num > 9 || vistos[num]) {
                        return 0;
                    }
                    vistos[num] = 1;
                }
            }
        }
    }

    return 1; 
}

int main() {
    int n, instancia;
    scanf("%d", &n);

    for (instancia = 1; instancia <= n; instancia++) {
        int matrizSudoku[9][9];
        int i, j;

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &matrizSudoku[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);

        if (validaSudoku(matrizSudoku)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
