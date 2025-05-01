
#include "image.h"

tImage ImAllouer(int NbLignes, int NbColonnes) {
    tImage img = malloc(sizeof(struct sImage));
    if (!img) return NULL;

    img->NbLig = NbLignes;
    img->NbCol = NbColonnes;
    img->NivGris = malloc(NbLignes * sizeof(tMatrice));
    if (!img->NivGris) {
        free(img);
        return NULL;
    }
    for (int i = 0; i < NbLignes; i++) {
        img->NivGris[i] = malloc(NbColonnes * sizeof(int));
        if (!img->NivGris[i]) {
            for (int j = 0; j < i; j++) {
                free(img->NivGris[j]);
            }
            free(img->NivGris);
            free(img);
            return NULL;
        }
    }
    return img;
}

void ImLiberer(tImage *pIm) {
    if (pIm && *pIm) {
        for (int i = 0; i < (*pIm)->NbLig; i++) {
            free((*pIm)->NivGris[i]);
        }
        free((*pIm)->NivGris);
        free(*pIm);
        *pIm = NULL;
    }
}

int ImNbLig(tImage Im) {
    return Im->NbLig;
}

int ImNbCol(tImage Im) {
    return Im->NbCol;
}

tMatrice ImNivGris(tImage Im) {
    return Im->NivGris;
}

tImage ImLire(char NomFichier[]) {
    FILE *fichier = fopen(NomFichier, "r");
    if (!fichier) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", NomFichier);
        return NULL;
    }
    char ligne[256];
    int NbLig, NbCol, maxNivGris;
    if (!fgets(ligne, sizeof(ligne), fichier) || strcmp(ligne, "P2\n") != 0) {
        fprintf(stderr, "Format de fichier non valide\n");
        fclose(fichier);
        return NULL;
    }
    if (fgets(ligne, sizeof(ligne), fichier) == NULL || sscanf(ligne, "%d %d", &NbCol, &NbLig) != 2) {
        fprintf(stderr, "Erreur de lecture des dimensions\n");
        fclose(fichier);
        return NULL;
    }
    if (fgets(ligne, sizeof(ligne), fichier) == NULL || sscanf(ligne, "%d", &maxNivGris) != 1) {
        fprintf(stderr, "Erreur de lecture du niveau de gris\n");
        fclose(fichier);
        return NULL;
    }
    tImage img = ImAllouer(NbLig, NbCol);
    if (!img) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        fclose(fichier);
        return NULL;
    }
    for (int i = 0; i < NbLig; i++) {
        for (int j = 0; j < NbCol; j++) {
            if (fscanf(fichier, "%s", &img->NivGris[i][j]) != 1) {
                fprintf(stderr, "Erreur de lecture des pixels\n");
                ImLiberer(&img);
                fclose(fichier);
                return NULL;
            }
        }
    }
    fclose(fichier);
    return img;
}

void ImEcrire(tImage Im, char NomFichier[]) {
    FILE *fichier = fopen(NomFichier, "w");
    if (!fichier) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", NomFichier);
        return;
    }
    fprintf(fichier, "P2\n");
    fprintf(fichier, "%d %d\n", ImNbCol(Im), ImNbLig(Im));
    fprintf(fichier, "255\n");
    for (int i = 0; i < ImNbLig(Im); i++) {
        for (int j = 0; j < ImNbCol(Im); j++) {
            fprintf(fichier, "%d ", ImNivGris(Im)[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
    printf("Image écrite avec succès dans %s\n", NomFichier);
    ImLiberer(&Im);
    return;
}

void ImRot(tImage img) {
    
}

