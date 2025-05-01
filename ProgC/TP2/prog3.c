#include <stdio.h>

int main(void) {
    int n;
    double somme = 0, note;

    printf("Entrez le nombre de notes : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        do {
            printf("Note %d (0-20) : ", i + 1);
            scanf("%lf", &note);
        } while (note < 0 || note > 20);
        
        somme += note;
    }

    printf("Moyenne des notes : %.2lf\n", somme / n);
    return 0;
}
