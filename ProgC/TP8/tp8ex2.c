
#include "image.h"

int main(void) {
    tImage img = ImLire("feep.pgm");
    if (img == NULL) {
        fprintf(stderr, "Erreur de lecture de l'image.\n");
        return 1;
    }
    printf("Image lue avec succès : %d lignes, %d colonnes.\n", ImNbLig(img), ImNbCol(img));
    ImLiberer(&img);

    img = ImLire("feep.pgm");
    if (img == NULL) {
        fprintf(stderr, "Erreur de lecture de l'image.\n");
        return 1;
    }
    ImRot(img);
    printf("Image après rotation : %d lignes, %d colonnes.\n", ImNbLig(img), ImNbCol(img));
    ImLiberer(&img);

    return 0;
}
