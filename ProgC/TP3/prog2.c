#include <math.h>
#include <stdio.h>

int main(void) {
  int n;
  printf("Entrez l'ordre de la matrice: ");
  scanf("%d", &n);

  double mat[n][n];
  printf("Entrez les valeurs ligne par ligne:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &mat[i][j]);
    }
  }

  int sym = 1;
  float epsilon = 10e-10;
  int i = 0;
  
  while (i < n && sym) {
    int j = 0;
    while (j < i && sym) {
      if (fabs(mat[i][j] - mat[j][i]) >= epsilon) {
        sym = 0;
      }
      j++;
    }
    i++;
  }

  if (sym) {
    printf("La matrice est symétrique.\n");
  } else {
    printf("La matrice n'est pas symétrique.\n");
  }

  return 0;
}