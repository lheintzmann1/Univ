#include <stdlib.h>
#include <stdio.h>

typedef unsigned char **tMatrice;

tMatrice MatAllouer(int NbLig, int NbCol) {
    tMatrice mat = malloc(NbLig * sizeof(unsigned char *));
    for (int i = 0; i < NbLig; i++) {
        mat[i] = malloc(NbCol * sizeof(unsigned char));
    }
    return mat;
}

tMatrice MatLire(int *pNbLig, int *pNbCol) {
    printf("Nombre de lignes: ");
    scanf("%d", pNbLig);
    printf("Nombre de colonnes: ");
    scanf("%d", pNbCol);
    tMatrice mat = MatAllouer(*pNbLig, *pNbCol);
    for (int i = 0; i < *pNbLig; i++) {
        for (int j = 0; j < *pNbCol; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%hhu", &mat[i][j]);
        }
    }
    printf("Nombre de lignes: %d\n", *pNbLig);
    printf("Nombre de colonnes: %d\n", *pNbCol);
    return mat;   
}

void MatAfficher(tMatrice mat, int NbLig, int NbCol) {
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

tMatrice MatCopier(tMatrice mat, int NbLig, int NbCol) {
    tMatrice copie = MatAllouer(NbLig, NbCol);
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            copie[i][j] = mat[i][j];
        }
    }
    return copie;
}

void MatLiberer(tMatrice *pMat) {
    for (int i = 0; i < sizeof(*pMat); i++) {
        free((*pMat)[i]);
    }
    free(*pMat);
    *pMat = NULL;
}

