#include <stdio.h>
#include <stdlib.h>

void Trier(int Tab[], int NbElts) {
    int i, j, temp;
    for (i = 0; i < NbElts; i++) {
        for (j = i + 1; j < NbElts; j++) {
        if (Tab[i] > Tab[j]) {
            temp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = temp;
            }
        }
    }    
}

void Aff(int Tab[], int NbElts) {
    int i;
    for (i = 0; i < NbElts; i++) {
        printf("%d ", Tab[i]);
    }
    printf("\n");
}

void TrierPtr(int Tab[], int NbElts, int *Ptr[]) {
    int i, j, temp;
    for (i = 0; i < NbElts; i++) {
        for (j = i + 1; j < NbElts; j++) {
        if (*Ptr[i] > *Ptr[j]) {
            temp = *Ptr[i];
            *Ptr[i] = *Ptr[j];
            *Ptr[j] = temp;
            }
        }
    }
}

void AffPtr(int *TabP[], int NbElts) {
    int i;
    for (i = 0; i < NbElts; i++) {
        printf("%d ", *TabP[i]);
    }
    printf("\n");
}

int main(void) {
    int Tableau[3]={3,1,2};
    int *TableauP[3];
    TrierPtr(Tableau,3,TableauP);
    AffPtr(TableauP,3);
    return 0;
}



