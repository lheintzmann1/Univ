#include "image.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Vérification des arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <fichier_source.pgm> <fichier_destination.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Lecture de l'image source
    printf("Lecture de l'image %s...\n", argv[1]);
    tImage imageSource = ImLire(argv[1]);
    if (imageSource == NULL) {
        fprintf(stderr, "Erreur lors de la lecture de l'image source\n");
        return EXIT_FAILURE;
    }
    
    printf("Image source: %d lignes x %d colonnes\n", ImNbLig(imageSource), ImNbCol(imageSource));
    
    // Rotation de l'image de 90°
    printf("Rotation de l'image de 90°...\n");
    tImage imageRotation = ImRotation90(imageSource);
    if (imageRotation == NULL) {
        fprintf(stderr, "Erreur lors de la rotation de l'image\n");
        ImLiberer(&imageSource);
        return EXIT_FAILURE;
    }
    
    printf("Image après rotation: %d lignes x %d colonnes\n", ImNbLig(imageRotation), ImNbCol(imageRotation));
    
    // Écriture de l'image résultante
    printf("Écriture de l'image résultante dans %s...\n", argv[2]);
    ImEcrire(imageRotation, argv[2]);
    
    // Libération de la mémoire
    ImLiberer(&imageSource);
    ImLiberer(&imageRotation);
    
    printf("Traitement terminé avec succès\n");
    return EXIT_SUCCESS;
}