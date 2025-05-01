#include <stdio.h>

double carre(double x) {
    return x * x;
}

int main(void) {
    double x;
    printf("Entrez un nombre : ");
    fflush(stdout);
    scanf("%lf", &x);
    double result = carre(x);
    printf("Le carré de %lf est %lf\n", x, result);
    return 0;
}

