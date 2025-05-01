
#include <stdio.h>

int main(void) {
    int n, somme = 0;
    while (n != 0) {
        printf("Entrez un entier : ");
        scanf("%d", &n);
        if (n < 0) {
            somme += n;
        }
    }
    printf("La somme des entiers négatifs est %d\n", somme);
    return 0;
}