#include <stdio.h>
#include <stdlib.h>

int main () {
    int Q;
    scanf("%d", &Q);
    int *mem = (int *)malloc(Q * sizeof(int));
    for (int i = 0; i < Q; i++) {
        mem[i] = -1;
    }

    int N;
    scanf("%d", &N);

    int index = 0, pageFault = 0;
    int find;
    for (int i = 0; i < N; i++) {
        int P;
        scanf("%d", &P);
        find = 1;

        for (int j = 0; j < Q; j++) {
            if (P == mem[j]) {
                find = 0;
                break;
            }
        }

        if (find == 1) {
            pageFault++;
            mem[index] = P;
            index = (index + 1) % Q;
        }
    }

    printf("%d\n", pageFault);

    return 0;
}