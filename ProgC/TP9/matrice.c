#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

tMatrice MatAllouer(int NbLig, int NbCol) {
    if (NbLig <= 0 || NbCol <= 0) {
        return NULL;
    }
    
    unsigned char *elements = (unsigned char *)malloc(NbLig * NbCol * sizeof(unsigned char));
    if (elements == NULL) {
        return NULL;
    }
    
    tMatrice mat = (tMatrice)malloc(NbLig * sizeof(unsigned char *));
    if (mat == NULL) {
        free(elements);
        return NULL;
    }
    
    for (int i = 0; i < NbLig; i++) {
        mat[i] = elements + (i * NbCol);
    }
    
    return mat;
}

tMatrice MatLire(int *pNbLig, int *pNbCol) {
    printf("Nombre de lignes : ");
    if (scanf("%d", pNbLig) != 1 || *pNbLig <= 0) {
        fprintf(stderr, "Erreur: nombre de lignes invalide\n");
        return NULL;
    }
    
    printf("Nombre de colonnes : ");
    if (scanf("%d", pNbCol) != 1 || *pNbCol <= 0) {
        fprintf(stderr, "Erreur: nombre de colonnes invalide\n");
        return NULL;
    }
    
    tMatrice mat = MatAllouer(*pNbLig, *pNbCol);
    if (mat == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return NULL;
    }
    
    printf("Saisie des éléments de la matrice :\n");
    for (int i = 0; i < *pNbLig; i++) {
        printf("Ligne %d :\n", i + 1);
        for (int j = 0; j < *pNbCol; j++) {
            unsigned int val;
            printf("Element[%d][%d] : ", i, j);
            if (scanf("%u", &val) != 1) {
                fprintf(stderr, "Erreur de lecture\n");
                MatLiberer(&mat);
                return NULL;
            }
            if (val > 255) {
                fprintf(stderr, "Erreur: valeur hors de l'intervalle [0, 255]\n");
                MatLiberer(&mat);
                return NULL;
            }
            mat[i][j] = (unsigned char)val;
        }
    }
    
    return mat;
}

void MatAfficher(tMatrice Mat, int NbLig, int NbCol) {
    if (Mat == NULL) {
        fprintf(stderr, "Matrice NULL\n");
        return;
    }
    
    printf("Matrice %d x %d :\n", NbLig, NbCol);
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            printf("%3d ", (int)Mat[i][j]);
        }
        printf("\n");
    }
}

tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol) {
    if (Mat == NULL || NbLig <= 0 || NbCol <= 0) {
        return NULL;
    }
    
    tMatrice copie = MatAllouer(NbLig, NbCol);
    if (copie == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            copie[i][j] = Mat[i][j];
        }
    }
    
    return copie;
}

void MatLiberer(tMatrice *pMat) {
    if (pMat != NULL && *pMat != NULL) {
        free((*pMat)[0]);
        
        free(*pMat);
        
        *pMat = NULL;
    }
}