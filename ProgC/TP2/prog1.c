#include <stdio.h>

int main(void) {
    int year;
    printf("Saisissez une année : ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("L'année %d est bissextile.\n", year);
    } else {
        printf("L'année %d n'est pas bissextile.\n", year);
    }
    return 0;
}
