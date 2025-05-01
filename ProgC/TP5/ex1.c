#include <stdio.h>

#define MAX 80

int Lecture(char * ch, int NbCarMax) {
  int i = 0;
  char c;
  while ((c = getchar()) != '\n' && i < NbCarMax) {
    ch[i] = c;
    i++;
  }

  ch[i] = '\0';

  return i;
}

int Longueur(char * ch) {
  int i = 0;
  while (ch[i] != '\0') {
    i++;
  }
  return i;
}

void Copie(char * ch1, char * ch2) {
  int i = 0;
  while (ch2[i] != '\0') {
    ch1[i] = ch2[i];
    i++;
  }
  ch1[i] = '\0';
}

int Differentes(char * ch1, char * ch2) {
  int i = 0;
  while (ch1[i] != '\0' && ch2[i] != '\0') {
    if (ch1[i] != ch2[i]) {
      return 1;
    }
    i++;
  }
  if (ch1[i] != ch2[i]) {
    return 1;
  }
  return 0;
}

void Ajout(char * Destination, char * Source) {
  int i = 0;
  while (Destination[i] != '\0') {
    i++;
  }
  int j = 0;
  while (Source[j] != '\0') {
    Destination[i] = Source[j];
    i++;
    j++;
  }
  Destination[i] = '\0';
}


int main(void) {
  char ch1[MAX + 1], ch2[2 * MAX + 1], ch3[MAX + 1] = "o";
  int n;
  
  printf("Test de Lecture\n---------------\n");
  printf("Tapez une chaine d'au plus %d caracteres : ", MAX);
  n = Lecture(ch1, MAX);
  printf("La chaine \"%s\" a ete lue ; elle contient %d caracteres.\n", ch1, n);
  printf("\nTest de Longueur\n----------------\n");
  printf("La chaine \"%s\" contient %d caracteres.\n", ch1, Longueur(ch1));
  printf("\nTest de copie\n-------------\n");
  Copie(ch2, ch1);
  printf("ch1=\"%s\", ch2=\"%s\"\n", ch1, ch2);
  printf("\nTest de Differentes\n-------------------\n");

  while (Differentes(ch3, "n")) {
    printf("Tapez une premiere chaine : ");
    Lecture(ch1, MAX);
    printf("Tapez une seconde chaine : ");
    Lecture(ch2, MAX);
    if (Differentes(ch1, ch2)) printf("%s et %s ne contiennent pas les mêmes caracteres.\n", ch1, ch2);
    else printf("%s et %s contiennent les memes caracteres.\n", ch1, ch2);
    printf("Voulez-vous continuer le test de Differentes "
      "(tapez n pour arreter) : ");
    Lecture(ch3, 1);
  }

  printf("\nTest de Ajout\n-------------\n");
  Copie(ch3, "o");

  while (Differentes(ch3, "n")) {
    printf("Tapez une premiere chaine : ");
    Lecture(ch1, MAX);
    printf("Tapez une seconde chaine : ");
    Lecture(ch2, MAX);
    printf("Ajout de la premiere chaine a la seconde :\n");
    Ajout(ch2, ch1);
    printf("ch1=\"%s\", ch2=\"%s\"\n", ch1, ch2);
    printf("Voulez-vous continuer le test de Ajout (tapez n pour arreter) : ");
    Lecture(ch3, 1);
  }

  return 0;
}