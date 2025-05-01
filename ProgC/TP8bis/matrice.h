#ifndef MATRICE_H
#define MATRICE_H

typedef unsigned char **tMatrice;

/* Alloue et initialise l'espace mémoire pour une matrice */
extern tMatrice MatAllouer(int NbLig, int NbCol);

/* Lit une matrice depuis l'entrée standard */
extern tMatrice MatLire(int *pNbLig, int *pNbCol);

/* Affiche une matrice à l'écran */
extern void MatAfficher(tMatrice Mat, int NbLig, int NbCol);

/* Réalise une copie de la matrice */
extern tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol);

/* Libère l'espace mémoire occupé par une matrice */
extern void MatLiberer(tMatrice *pMat);

#endif /* MATRICE_H */