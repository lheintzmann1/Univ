#include <stdio.h>

int main(void) {
  int n;
  printf("Entrez le nombre de lignes : ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
