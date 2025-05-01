#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Ecrivez un entier: ");
    double n;
    scanf("%lf", &n);
    printf("La racine carrée de %lf est %lf\n", n, sqrt(n));
    return 0;
}
