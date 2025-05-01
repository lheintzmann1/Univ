#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

tMatrice MatAllouer(int NbLig, int NbCol) {
    // Vérification des paramètres
    if (NbLig <= 0 || NbCol <= 0) {
        return NULL;
    }
    
    // Allocation du tableau d'éléments
    unsigned char *elements = (unsigned char *)malloc(NbLig * NbCol * sizeof(unsigned char));
    if (elements == NULL) {
        return NULL;
    }
    
    // Allocation du tableau de pointeurs
    tMatrice mat = (tMatrice)malloc(NbLig * sizeof(unsigned char *));
    if (mat == NULL) {
        free(elements);
        return NULL;
    }
    
    // Initialisation des pointeurs vers le début de chaque ligne
    for (int i = 0; i < NbLig; i++) {
        mat[i] = elements + (i * NbCol);
    }
    
    return mat;
}

tMatrice MatLire(int *pNbLig, int *pNbCol) {
    // Demande du nombre de lignes et de colonnes
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
    
    // Allocation de la matrice
    tMatrice mat = MatAllouer(*pNbLig, *pNbCol);
    if (mat == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return NULL;
    }
    
    // Lecture des éléments
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
            // Vérification que la valeur est bien dans l'intervalle d'un unsigned char
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
    
    // Allocation de la copie
    tMatrice copie = MatAllouer(NbLig, NbCol);
    if (copie == NULL) {
        return NULL;
    }
    
    // Copie des éléments
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            copie[i][j] = Mat[i][j];
        }
    }
    
    return copie;
}

void MatLiberer(tMatrice *pMat) {
    if (pMat != NULL && *pMat != NULL) {
        // Libération du tableau d'éléments (la première ligne contient l'adresse de tout le bloc)
        free((*pMat)[0]);
        
        // Libération du tableau de pointeurs
        free(*pMat);
        
        // Mise à NULL du pointeur pour éviter une double libération
        *pMat = NULL;
    }
}