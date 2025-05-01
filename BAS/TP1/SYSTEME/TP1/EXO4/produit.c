// Faire le produit de deux entiers saisis par l'utilisateur
#include <stdio.h>

int main (void) {
  // Declaration des variables (entieres) utiles
  int n1, n2, produit;

  // Saisie des valeurs
  printf("Veuillez entrer un entier ");
  scanf("%d", &n1);
  printf("Veuillez entrer un autre entier ");
  scanf("%d", &n2);

  // Calcul du produit
  produit = n1 * n2;

  // Affichage du resultat
  printf("Produit de %d et %d = %d\n", n1, n2, produit);

  return 0;

}

