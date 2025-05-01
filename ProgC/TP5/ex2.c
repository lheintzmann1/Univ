
#include <stdio.h>
#include <stdlib.h>

double *CreerTableau(int NbElts) {
    double *tab = malloc(NbElts * sizeof(double));
    return tab;
}

void SaisirTableau(double *Tab, int NbElts) {
    for (int i = 0; i < NbElts; i++) {
        printf("Saisir la valeur d'index %d: ", i);
        scanf("%lf", &Tab[i]);
    }
}

void AfficherTableau(double *Tab, int NbElts) {
    for (int i = 0; i < NbElts; i++) {
        printf("Tab[%d] = %lf\n", i, Tab[i]);
    }
}

void LibererTableau(double *Tab) {
    free(Tab);
}

int main() {
    int NbElts;
    printf("Saisir le nombre d'elements: ");
    scanf("%d", &NbElts);

    double *Tab = CreerTableau(NbElts);
    if (Tab == NULL) {
        printf("Erreur d'allocation de memoire\n");
        return 1;
    }

    SaisirTableau(Tab, NbElts);
    AfficherTableau(Tab, NbElts);
    LibererTableau(Tab);

    return 0;
}