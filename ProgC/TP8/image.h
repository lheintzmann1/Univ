
#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrice.h"

typedef struct sImage *tImage;

struct sImage
{
int NbLig ;
int NbCol ;
tMatrice NivGris ;
};

tImage ImAllouer(int NbLignes, int NbColonnes);
void ImLiberer(tImage *pIm);
int ImNbLig(tImage Im);
int ImNbCol(tImage Im);
tMatrice ImNivGris(tImage Im);
tImage ImLire(char NomFichier[]);
void ImEcrire(tImage Im, char NomFichier[]);
void ImRot(tImage img);

#endif
