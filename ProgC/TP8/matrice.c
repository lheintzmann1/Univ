
#include "matrice.h"

tMatrice MatAllouer(int NbLig, int NbCol) {
    /*
    tMatrice mat = malloc(NbLig * sizeof(unsigned char *));
    if (!mat) return NULL;
    
    for (int i = 0; i < NbLig; i++) {
        mat[i] = malloc(NbCol * sizeof(unsigned char));
        if (!mat[i]) {
            for (int k = 0; k < i; k++) free(mat[k]);
            free(mat);
            return NULL;
        }
    }
    return mat;
    */
    tMatrice mat = malloc(NbLig * sizeof(unsigned char *));
    if (!mat) return NULL;
    unsigned char *data = malloc(NbLig * NbCol * sizeof(unsigned char));
    if (!data) {
        free(mat);
        return NULL;
    }
    for (int i = 0; i < NbLig; i++) {
        mat[i] = data + i * NbCol;
    }
    return mat;
}
    
tMatrice MatCopier(tMatrice mat, int NbLig, int NbCol) {
    tMatrice copie = MatAllouer(NbLig, NbCol);
    if (!copie) return NULL;
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            copie[i][j] = mat[i][j];
        }
    }
    return copie;
}

void MatLiberer(tMatrice *pMat, int NbLig) {
    if (pMat && *pMat) {
        free((*pMat)[0]);
        free(*pMat);
        *pMat = NULL;
    }
}

tMatrice MatLire(int *pNbLig, int *pNbCol) {
    int NbLig, NbCol;
    printf("Entrez le nombre de lignes: ");
    scanf("%d", &NbLig);
    printf("Entrez le nombre de colonnes: ");
    scanf("%d", &NbCol);

    tMatrice mat = MatAllouer(NbLig, NbCol);
    if (!mat) return NULL;

    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            printf("Entrez l'element [%d][%d]: ", i, j);
            scanf("%hhu", &mat[i][j]);
        }
    }

    *pNbLig = NbLig;
    *pNbCol = NbCol;
    return mat;
}

void MatAfficher(tMatrice mat, int NbLig, int NbCol) {
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            printf("%hhu ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
