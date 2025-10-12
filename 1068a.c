#include <stdio.h>

#define T_PILHA 512

int main(void) {
    int c;

    while (1) {
        char pilha[T_PILHA];
        int topo = -1;
        int ok = 1, any = 0;

        while ((c = getchar()) != EOF && c != '\n') {
            any = 1;

            if (c == '(') {
                if (topo < T_PILHA - 1) {
                    topo++;
                    pilha[topo] = '(';
                } else {
                    ok = 0;
                }
            } else if (c == ')') {
                if (topo == -1) {
                    ok = 0;
                } else {
                    topo--;
                }
            }
        }

        if (!any && c == EOF) break;

        if (ok && topo == -1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        if (c == EOF) break;
    }
    return 0;
}
