#include <stdio.h>

void AfficherTab(int Tab[], int NbElt) {
    int i;
    for (i = 0; i < NbElt; i++) {
        printf("%d ", Tab[i]);
    }
    printf("\n");
}

int Min(int Tab[], int NbElt) {
    int i, min = Tab[0];
    for (i = 1; i < NbElt; i++) {
        if (Tab[i] < min) {
            min = Tab[i];
        }
    }
    return min;
}

int Max(int Tab[], int NbElt) {
    int i, max = Tab[0];
    for (i = 1; i < NbElt; i++) {
        if (Tab[i] > max) {
            max = Tab[i];
        }
    }
    return max;
}

int MinMax(int Tab[], int NbElt, int *pMin, int *pMax) {
    *pMin = Min(Tab, NbElt);
    *pMax = Max(Tab, NbElt);
    return 0;
}

int pMinMax(int Tab[], int NbElt, int **pMin, int **pMax) {
    *pMin = &Tab[0];
    *pMax = &Tab[0];
    int i;
    for (i = 1; i < NbElt; i++) {
        if (Tab[i] < **pMin) {
            *pMin = &Tab[i];
        }
        if (Tab[i] > **pMax) {
            *pMax = &Tab[i];
        }
    }
    return 0;
}

int SupprimerVal(int Tab[], int *pNbElt, int Val) {
    int i;
    int j;
    int nbSupp = 0;
    for (i = 0; i < *pNbElt; i++) {
        if (Tab[i] == Val) {
            for (j = i; j < *pNbElt - 1; j++) {
                Tab[j] = Tab[j + 1];
            }
            i--;
            nbSupp++;
            (*pNbElt)--;
        }
    }
    printf("Nombre de valeurs supprimées: %d\n", nbSupp);
    printf("Le tableau contient désormais %d éléments\n", *pNbElt);
    return 0;
}

int main(void) {
    int Tab[5] = {1, 2, 3, 4, 5};

    AfficherTab(Tab, 5);

    printf("Min = %d\n", Min(Tab, 5));
    printf("Max = %d\n", Max(Tab, 5));

    int min, max;
    MinMax(Tab, 5, &min, &max);
    printf("Min = %d, Max = %d\n", min, max);

    int* pMin;
    int* pMax;
    pMinMax(Tab, 5, &pMin, &pMax);
    printf("Min = %p, Max = %p\n", &pMin, &pMax);

    int NbElt = 5;
    SupprimerVal(Tab, &NbElt, 3);
    AfficherTab(Tab, 4);

    return 0;
}

