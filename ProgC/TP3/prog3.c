#include <stdio.h>

int main(void) {
  char chaine[81];
  int i = 0;
  char c;

  printf("Entrez une chaine de caractères: ");
  int continuerLecture = 1;
  while (continuerLecture && i < 80) {
    c = getchar();
    if (c != '\n') {
      chaine[i] = c;
      i++;
    } else {
      continuerLecture = 0;
    }
  }
  chaine[i] = '\0';

  for (int j = 0; j < i; j++) {
    if (chaine[j] == ' ') {
      int k = j;
      while (k < i) {
        chaine[k] = chaine[k + 1];
        k++;
      }
      i--;
      j--;
    }
  }

  printf("Chaine : %s\nNombre de caractères : %d\n", chaine, i);

  char inverted[81];
  for (int j = 0; j < i; j++) {
    inverted[j] = chaine[i - j - 1];
  }
  inverted[i] = '\0';
  printf("Chaine inversée : %s\n", inverted);

  int y = 0;
  int isPal = 1;
  int finChaine = 0;
  
  while (!finChaine && isPal) {
    if (chaine[y] == '\0') {
      finChaine = 1;
    } else {
      if (chaine[y] != ' ') {
        if (chaine[y] != inverted[y]) {
          isPal = 0;
        }
      }
      y++;
    }
  }

  if (isPal) {
    printf("La chaine est un palindrome\n");
  } else {
    printf("La chaine n'est pas un palindrome\n");
  }

  return 0;
}