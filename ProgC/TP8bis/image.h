#ifndef IMAGE_H
#define IMAGE_H

#include "matrice.h"

/* Type public pour manipuler les images */
typedef struct sImage *tImage;

/* Structure d'implémentation (définie dans image.c) */
struct sImage {
    int NbLig;         // Nombre de lignes de l'image
    int NbCol;         // Nombre de colonnes de l'image
    tMatrice NivGris;  // Matrice des niveaux de gris de l'image
};

/* Fonctions de base */
extern tImage ImAllouer(int NbLignes, int NbColonnes);
extern void ImLiberer(tImage *pIm);
extern int ImNbLig(tImage Im);
extern int ImNbCol(tImage Im);
extern tMatrice ImNivGris(tImage Im);

/* Fonctions d'entrées-sorties */
extern tImage ImLire(char NomFichier[]);
extern void ImEcrire(tImage Im, char NomFichier[]);

/* Fonction de rotation */
extern tImage ImRotation90(tImage imageSource);

#endif /* IMAGE_H */