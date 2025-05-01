#include <stdio.h>
#include <stdlib.h>

typedef unsigned char **tMatrice;

tMatrice MatAllouer(int NbLig, int NbCol) {
    tMatrice mat = malloc(NbLig * sizeof(unsigned char *));
    for (int i = 0; i < NbLig; i++) {
        mat[i] = malloc(NbCol * sizeof(unsigned char));
    }
    return mat;
}

void MatLiberer(tMatrice *pMat) {
    for (int i = 0; i < sizeof(*pMat); i++) {
        free((*pMat)[i]);
    }
    free(*pMat);
    *pMat = NULL;
}

// triangle de pascal
tMatrice Triangle(int n) {
    tMatrice mat = MatAllouer(n, n);
    for (int i = 0; i < n; i++) {
        mat[i][0] = 1;
        mat[i][i] = 1;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
        }
    }
    return mat;
}

void AffTriangle(tMatrice mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Entrez un entier n: ");
    scanf("%d", &n);
    tMatrice mat = Triangle(n);
    AffTriangle(mat, n);
    MatLiberer(&mat);
    return 0;
}


