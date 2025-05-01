
#include <stdio.h>

int main(void) {
	char texte[100];
	char c;
	int i = 0;

	printf("Entrez un texte se terminant par $ :\n");
	while (i < 100 && (c = getchar()) != '$') {
		texte[i] = c;
		i++;
	}

	printf("Texte inversé :\n");
	for (int j = i - 1; j >= 0; j--) {
		putchar(texte[j]);
	}
	printf("\n");

	return 0;
}

