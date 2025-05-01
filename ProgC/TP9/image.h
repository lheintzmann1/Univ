#ifndef IMAGE_H
#define IMAGE_H

#include "matrice.h"

typedef struct sImage *tImage;

struct sImage {
    int NbLig;
    int NbCol;
    tMatrice NivGris;
};

extern tImage ImAllouer(int NbLignes, int NbColonnes);
extern void ImLiberer(tImage *pIm);
extern int ImNbLig(tImage Im);
extern int ImNbCol(tImage Im);
extern tMatrice ImNivGris(tImage Im);

extern tImage ImLire(char NomFichier[]);
extern void ImEcrire(tImage Im, char NomFichier[]);

extern tImage ImRotation90(tImage imageSource);

#endif