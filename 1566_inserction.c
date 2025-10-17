#include <stdio.h>
#include <stdlib.h>

static void ins(int *v, int n) {
    int f[211];                  
    for (int i = 0; i < 211; i++) f[i] = 0;     

    for (int i = 0; i < n; i++) {
        int h = v[i];
        if (h >= 20 && h <= 230) f[h - 20]++;   
    }

    int k = 0;
    for (int i = 0; i < 211; i++) {             
        while (f[i] > 0) {
            v[k++] = i + 20;
            f[i]--;
        }
    }
}

int main(void) {
    int c;
    if (scanf("%d", &c) != 1) return 0;
    while (c--) {
        int n;
        scanf("%d", &n);
        int *v = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);

        ins(v, n);

        for (int i = 0; i < n; i++) {
            if (i) putchar(' ');
            printf("%d", v[i]);
        }
        putchar('\n');
        free(v);
    }
    return 0;
}
