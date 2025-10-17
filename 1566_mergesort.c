#include <stdio.h>
#include <stdlib.h>

static void mg(int *v, int l, int m, int r, int *t) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (v[i] <= v[j]) t[k++] = v[i++];
        else               t[k++] = v[j++];
    }
    while (i <= m) t[k++] = v[i++];
    while (j <= r) t[k++] = v[j++];
    for (int a = l; a <= r; a++) v[a] = t[a];
}

static void ms(int *v, int l, int r, int *t) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    ms(v, l, m, t);
    ms(v, m + 1, r, t);
    mg(v, l, m, r, t);
}

int main(void) {
    int c;
    if (scanf("%d", &c) != 1) return 0;
    while (c--) {
        int n;
        scanf("%d", &n);
        int *v = (int*)malloc(sizeof(int) * n);
        int *t = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);

        ms(v, 0, n - 1, t);

        for (int i = 0; i < n; i++) {
            if (i) putchar(' ');
            printf("%d", v[i]);
        }
        putchar('\n');
        free(t);
        free(v);
    }
    return 0;
}
