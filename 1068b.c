#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char ch;
    struct No* prox;
} No;

int main(void) {
    int c;

    while (1) {
        No* top = NULL;
        int ok = 1, any = 0;

        while ((c = getchar()) != EOF && c != '\n') {
            any = 1;

            if (c == '(') {
                No* novo = (No*) malloc(sizeof(No));
                if (novo == NULL) {
                    ok = 0;
                } else {
                    novo->ch = '(';
                    novo->prox = top;
                    top = novo;
                }
            } else if (c == ')') {
                if (top == NULL) {
                    ok = 0;
                } else {
                    No* temp = top;
                    top = top->prox;
                    free(temp);
                }
            }
        }

        if (!any && c == EOF) break;

        if (ok && top == NULL) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        
        while (top != NULL) {
            No* temp = top;
            top = top->prox;
            free(temp);
        }

        if (c == EOF) break;
    }
    return 0;
}
