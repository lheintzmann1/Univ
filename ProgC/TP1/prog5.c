#include <stdio.h>

int main(void) {
    int f;
    int c;
    printf("Température à convertir en °C: ");
    scanf("%d", &f);
    c = (f - 32) * 5 / 9;
    printf("%d°F = %d°C\n", f, c);
    return 0;
}
