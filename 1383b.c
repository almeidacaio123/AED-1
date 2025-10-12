#include <stdio.h>
#include <stdlib.h>

int validaS(int **g) {
    int i, j;

    for (i = 0; i < 9; i++) {
        int v[10] = {0};
        for (j = 0; j < 9; j++) {
            int n = g[i][j];
            if (n < 1 || n > 9 || v[n]) {
                return 0;
            }
            v[n] = 1;
        }
    }

    for (j = 0; j < 9; j++) {
        int v[10] = {0};
        for (i = 0; i < 9; i++) {
            int n = g[i][j];
            if (n < 1 || n > 9 || v[n]) {
                return 0;
            }
            v[n] = 1;
        }
    }

    for (int br = 0; br < 9; br += 3) {
        for (int bc = 0; bc < 9; bc += 3) {
            int v[10] = {0};
            for (i = br; i < br + 3; i++) {
                for (j = bc; j < bc + 3; j++) {
                    int n = g[i][j];
                    if (n < 1 || n > 9 || v[n]) {
                        return 0;
                    }
                    v[n] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, inst;
    scanf("%d", &n);

    for (inst = 1; inst <= n; inst++) {
        int **mat;
        int i, j;

        mat = (int **) malloc(9 * sizeof(int *));
        for (i = 0; i < 9; i++) {
            mat[i] = (int *) malloc(9 * sizeof(int));
        }

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        printf("Instancia %d\n", inst);

        if (validaS(mat)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        for (i = 0; i < 9; i++) {
            free(mat[i]);
        }
        free(mat);
    }

    return 0;
}
