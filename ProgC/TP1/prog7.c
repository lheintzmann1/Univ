#include <stdio.h>

int main(void) {
    float i[5], min, max;
    printf("Entrez 5 nombres réels: ");
    for (int j = 0; j < 5; j++) {
        scanf("%f", &i[j]);
    }
    min = max = i[0];
    for (int j = 1; j < 5; j++) {
        if (i[j] < min) {
            min = i[j];
        }
        if (i[j] > max) {
            max = i[j];
        }
    }
    printf("Le minimum est %f et le maximum est %f\n", min, max);
    return 0;
}
