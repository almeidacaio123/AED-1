#include <stdio.h>

int main() {
    char stack[1000];  
    int tp;
    int c;

    while (1) {
        tp = -1;
        int ok = 1;

        while ((c = getchar()) != EOF && c != '\n') {
            if (c == '(') {
                if (tp < 999) {
                    tp++;
                    stack[tp] = '(';
                } else {
                    ok = 0; 
                }
            } else if (c == ')') {
                if (tp == -1) {
                    ok = 0; 
                } else {
                    tp--;   
                }
            }
        }

        if (c == EOF) break;

        if (ok && tp == -1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}

