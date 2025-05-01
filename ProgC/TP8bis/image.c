#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

tImage ImAllouer(int NbLignes, int NbColonnes) {
    if (NbLignes <= 0 || NbColonnes <= 0) {
        return NULL;
    }
    
    tImage img = (tImage)malloc(sizeof(struct sImage));
    if (img == NULL) {
        return NULL;
    }
    
    img->NbLig = NbLignes;
    img->NbCol = NbColonnes;
    img->NivGris = MatAllouer(NbLignes, NbColonnes);
    
    if (img->NivGris == NULL) {
        free(img);
        return NULL;
    }
    
    return img;
}

void ImLiberer(tImage *pIm) {
    if (pIm != NULL && *pIm != NULL) {
        MatLiberer(&((*pIm)->NivGris));
        free(*pIm);
        *pIm = NULL;
    }
}

int ImNbLig(tImage Im) {
    if (Im == NULL) {
        return 0;
    }
    return Im->NbLig;
}

int ImNbCol(tImage Im) {
    if (Im == NULL) {
        return 0;
    }
    return Im->NbCol;
}

tMatrice ImNivGris(tImage Im) {
    if (Im == NULL) {
        return NULL;
    }
    return Im->NivGris;
}

tImage ImLire(char NomFichier[]) {
    FILE *fichier = fopen(NomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", NomFichier);
        return NULL;
    }
    
    // Lecture de la signature "P2"
    char signature[3];
    if (fscanf(fichier, "%2s", signature) != 1 || strcmp(signature, "P2") != 0) {
        fprintf(stderr, "Format de fichier non valide (attendu: P2)\n");
        fclose(fichier);
        return NULL;
    }
    
    int NbCol, NbLig, maxNivGris;
    
    // Lecture des dimensions
    if (fscanf(fichier, "%d %d", &NbCol, &NbLig) != 2 || NbCol <= 0 || NbLig <= 0) {
        fprintf(stderr, "Dimensions invalides\n");
        fclose(fichier);
        return NULL;
    }
    
    // Lecture du niveau de gris maximal
    if (fscanf(fichier, "%d", &maxNivGris) != 1 || maxNivGris <= 0) {
        fprintf(stderr, "Niveau de gris maximal invalide\n");
        fclose(fichier);
        return NULL;
    }
    
    // Allocation de l'image
    tImage img = ImAllouer(NbLig, NbCol);
    if (img == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        fclose(fichier);
        return NULL;
    }
    
    // Lecture des pixels
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            int valeur;
            if (fscanf(fichier, "%d", &valeur) != 1) {
                fprintf(stderr, "Erreur de lecture du pixel (%d,%d)\n", i, j);
                ImLiberer(&img);
                fclose(fichier);
                return NULL;
            }
            
            // Transformation des niveaux de gris
            if (valeur < 0 || valeur > maxNivGris) {
                fprintf(stderr, "Niveau de gris hors limites [0-%d]\n", maxNivGris);
                ImLiberer(&img);
                fclose(fichier);
                return NULL;
            }
            
            // Conversion de l'intervalle [0,maxNivGris] à [0,255]
            img->NivGris[i][j] = (unsigned char)round(255.0 * valeur / maxNivGris);
        }
    }
    
    fclose(fichier);
    return img;
}

void ImEcrire(tImage Im, char NomFichier[]) {
    if (Im == NULL) {
        fprintf(stderr, "Image invalide\n");
        return;
    }
    
    FILE *fichier = fopen(NomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s en écriture\n", NomFichier);
        return;
    }
    
    // Écriture de l'en-tête
    fprintf(fichier, "P2\n");
    fprintf(fichier, "%d %d\n", Im->NbCol, Im->NbLig);
    fprintf(fichier, "255\n");
    
    // Écriture des pixels
    for (int i = 0; i < Im->NbLig; i++) {
        for (int j = 0; j < Im->NbCol; j++) {
            fprintf(fichier, "%d ", (int)Im->NivGris[i][j]);
        }
        fprintf(fichier, "\n");
    }
    
    fclose(fichier);
    printf("Image écrite avec succès dans %s\n", NomFichier);
}

tImage ImRotation90(tImage imageSource) {
    if (imageSource == NULL) {
        return NULL;
    }
    
    int srcLig = imageSource->NbLig;
    int srcCol = imageSource->NbCol;
    
    // Dans une rotation de 90°, les lignes deviennent des colonnes et vice versa
    tImage imageRotation = ImAllouer(srcCol, srcLig);
    if (imageRotation == NULL) {
        return NULL;
    }
    
    // Effectuer la rotation de 90° (sens inverse des aiguilles d'une montre)
    for (int i = 0; i < srcLig; i++) {
        for (int j = 0; j < srcCol; j++) {
            // Le pixel (i,j) de l'image source devient le pixel (srcCol-1-j, i) dans l'image rotationée
            imageRotation->NivGris[srcCol-1-j][i] = imageSource->NivGris[i][j];
        }
    }
    
    return imageRotation;
}