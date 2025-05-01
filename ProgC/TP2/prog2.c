#include <stdio.h>

int main(void) {
    char c;
    int lettres = 0, voyelles = 0;

    printf("Entrez un texte (terminez avec #) : ");

    while ((c = getchar()) != '#') {
        if ((c >= 'a' && c <= 'z') || c == ' ') {
            if (c >= 'a' && c <= 'z') {
                lettres++;
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                    voyelles++;
                }
            }
        } else {
            printf("Caractère invalide : %c (code ASCII : %d)\n", c, c);
            return 1;
        }
    }

    printf("Nombre de lettres : %d\n", lettres);
    printf("Nombre de voyelles : %d\n", voyelles);

    return 0;
}
