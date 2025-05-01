// Faire la somme de deux entiers saisis par l'utilisateur
#include <stdio.h>

int main (void) {
  // Declaration des variables (entieres) utiles
  int n1, n2, somme;

  // Saisie des valeurs
  printf("Veuillez entrer un entier ");
  scanf("%d", &n1);
  printf("Veuillez entrer un autre entier ");
  scanf("%d", &n2);

  // Calcul de la somme
  somme = n1 + n2;

  // Affichage du resultat
  printf("Somme de %d et %d = %d\n", n1, n2, somme);

  return 0;

}

