#include <stdio.h>

int main(void) {
	int n = 0;
	int tab[n];
	int i;

	printf("Nombre de valeurs: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Valeur %d: ", i);
		scanf("%d", &tab[i]);
	}

	int sum = 0;
	for (i = 0; i < n; i++) {
		sum += tab[i];
	}
	printf("Moyenne des valeurs: %f\n", (float)sum / n);

	for (i = 0; i < n; i++) {
		if (tab[i] > (float)sum / n) {
			printf("%d est strictement supérieur à la moyenne\n", tab[i]);
		}
	}

	return 0;
}

