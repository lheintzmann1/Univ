#include <stdio.h>

void convert1(int time, int *sec, int *min, int *hours) {
    *hours = time / 3600;
    *min = (time % 3600) / 60;
    *sec = time % 60;
}

void convert2(int time, int result[3]) {
    result[0] = time / 3600;
    result[1] = (time % 3600) / 60;
    result[2] = time % 60;    
}

int main(void) {
    int time;
    int sec, min, hours;
    int result[3];

    printf("Entrez une durée en secondes: ");
    scanf("%d", &time);

    convert1(time, &sec, &min, &hours);
    printf("convert1: %d heure(s), %d minute(s), %d seconde(s)\n", hours, min, sec);

    convert2(time, result);
    printf("convert2: %d heure(s), %d minute(s), %d seconde(s)\n", result[0], result[1], result[2]);
    
    return 0;
}
