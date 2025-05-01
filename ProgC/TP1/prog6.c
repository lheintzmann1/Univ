#include <stdio.h>

int main(void) {
    unsigned char n, i;
    printf("Ecrivez un entier: ");
    scanf("%hhu", &n);
    i = n*n;
    printf("Le carré de %hhu est %hhu\n", n, i);
    return 0;
}

/*
16² = 256 > 255 (max unsigned char) 
=> overflow de i (i = 0)
*/
