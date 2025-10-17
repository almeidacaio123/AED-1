#include <stdio.h>
#include <stdlib.h>

static void down(int *v, int n, int i) {
    while (1) {
        int a = 2*i + 1, b = 2*i + 2, m = i;
        if (a < n && v[a] > v[m]) m = a;
        if (b < n && v[b] > v[m]) m = b;
        if (m == i) break;
        int x = v[i]; v[i] = v[m]; v[m] = x;
        i = m;
    }
}

static void hs(int *v, int n) {
    for (int i = n/2 - 1; i >= 0; i--) down(v, n, i);
    for (int e = n - 1; e > 0; e--) {
        int x = v[0]; v[0] = v[e]; v[e] = x;
        down(v, e, 0);
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

        hs(v, n);

        for (int i = 0; i < n; i++) {
            if (i) putchar(' ');
            printf("%d", v[i]);
        }
        putchar('\n');
        free(v);
    }
    return 0;
}
