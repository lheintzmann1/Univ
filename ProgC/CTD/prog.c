
#include <stdio.h>

int main(void) {
	int nbEtoiles = 0;
	printf("Nombre d'étoiles: ");
	fflush(stdout);
	scanf("&d", &nbEtoiles);
	for (int i = 0; i < nbEtoiles; i++) {
		printf("*");
	}
	printf("\n");
	return 0;
}

