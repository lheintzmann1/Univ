
#ifndef MATRICE_H
#define MATRICE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char **tMatrice;

extern tMatrice MatAllouer(int NbLig, int NbCol);
extern tMatrice MatCopier(tMatrice mat, int NbLig, int NbCol);
extern void MatLiberer(tMatrice *pMat, int NbLig);
extern tMatrice MatLire(int *pNbLig, int *pNbCol) ;
extern void MatAfficher(tMatrice mat, int NbLig, int NbCol);


#endif
