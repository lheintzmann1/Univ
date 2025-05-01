#include <stdio.h>

int main(void) {
    int a, b, temp;
    printf("Ecrivez deux entiers: ");
    scanf("%d %d", &a, &b);
    temp = a;
    a = b;
    b = temp;
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
