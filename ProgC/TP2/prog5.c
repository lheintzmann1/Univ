#include <stdio.h>

int main(void) {
    int N;

    do {
        printf("Entrez un entier N (0-18) : ");
        scanf("%d", &N);
    } while (N < 0 || N > 18);

    printf(" x |");
    for (int i = 0; i <= N; i++) {
        printf("%4d", i);
    }
    printf("\n---+");
    for (int i = 0; i <= N; i++) {
        printf("----");
    }
    printf("\n");

    for (int i = 0; i <= N; i++) {
        printf("%2d |", i);
        for (int j = 0; j <= N; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
