#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int q[60];          
        int dscrt[60];       
        int ctopo = 0;       
        int cbase = 0;       
        int quant  = 0;       
        int capac  = 60;      
        int contador = 0;
        int i;

       
        for (i = 1; i <= n; ++i) {
            q[cbase] = i;
            cbase = (cbase + 1) % capac;
            quant++;
        }

        while (quant > 1) {
            dscrt[contador++] = q[ctopo];
            ctopo = (ctopo + 1) % capac;
            quant--;

            {
                int x = q[ctopo];
                ctopo = (ctopo + 1) % capac;
                quant--;
                q[cbase] = x;
                cbase = (cbase + 1) % capac;
                quant++;
            }
        }

        printf("Discarded cards:");
        if (contador > 0) {
            printf(" ");
            for (i = 0; i < contador; ++i) {
                if (i) printf(", ");
