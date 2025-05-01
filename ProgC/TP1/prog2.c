#include <stdio.h>

int main(void) {
    printf("Ecrivez un entier: ");
    int n;
    scanf("%d", &n);
    printf("Le carré de %d est %d\n", n, n * n);
    return 0;
}
