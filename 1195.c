#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v;
    struct No *e, *d;
} No;

No* novo(int v) {
    No* n = (No*) malloc(sizeof(No));
    n->v = v;
    n->e = n->d = NULL;
    return n;
}

No* insere(No* r, int v) {
    if (r == NULL) return novo(v);
    if (v < r->v) r->e = insere(r->e, v);
    else r->d = insere(r->d, v);
    return r;
}

void pre(No* r, int *p) {
    if (r != NULL) {
        if (*p) *p = 0; else printf(" ");
        printf("%d", r->v);
        pre(r->e, p);
        pre(r->d, p);
    }
}

void in(No* r, int *p) {
    if (r != NULL) {
        in(r->e, p);
        if (*p) *p = 0; else printf(" ");
        printf("%d", r->v);
        in(r->d, p);
    }
}

void pos(No* r, int *p) {
    if (r != NULL) {
        pos(r->e, p);
        pos(r->d, p);
        if (*p) *p = 0; else printf(" ");
        printf("%d", r->v);
    }
}

void libera(No* r) {
    if (r != NULL) {
        libera(r->e);
        libera(r->d);
        free(r);
    }
}

int main() {
    int c;
    scanf("%d", &c);
    for (int k = 1; k <= c; k++) {
        int n;
        scanf("%d", &n);
        No* r = NULL;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            r = insere(r, x);
        }

        printf("Case %d:\n", k);

        int p = 1;
        printf("Pre.: ");
        pre(r, &p);
        printf("\n");

        p = 1;
        printf("In..: ");
        in(r, &p);
        printf("\n");

        p = 1;
        printf("Post: ");
        pos(r, &p);
        printf("\n\n");

        libera(r);
    }
    return 0;
}
