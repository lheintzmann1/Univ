
#include "matrice.h"

int main() {
    int NbLig, NbCol;
    tMatrice mat = MatLire(&NbLig, &NbCol);
    MatAfficher(mat, NbLig, NbCol);
    tMatrice copie = MatCopier(mat, NbLig, NbCol);
    MatAfficher(copie, NbLig, NbCol);
    MatLiberer(&mat, NbLig);
    MatLiberer(&copie, NbLig);
    return 0;
}
