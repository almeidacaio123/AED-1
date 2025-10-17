#include <stdio.h>
#include <stdlib.h>

static void sel(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[m]) m = j;
        if (m != i) { int x = v[i]; v[i] = v[m]; v[m] = x; }
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

        sel(v, n);

        for (int i = 0; i < n; i++) {
            if (i) putchar(' ');
            printf("%d", v[i]);
        }
        putchar('\n');
        free(v);
    }
    return 0;
}
