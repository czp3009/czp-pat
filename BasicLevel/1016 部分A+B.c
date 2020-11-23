#include <stdio.h>

int calculateP(const char array[10], char d) {
    //how many d in array
    int countD = 0;
    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == d) countD++;
    }

    //output a number
    int dValue = d - '0';
    int result = 0;
    for (int i = 0; i < countD; i++) {
        result = result * 10 + dValue;
    }
    return result;
}

int main() {
    char a[10], b[10];
    char Da, Db;
    scanf("%s %c %s %c", a, &Da, b, &Db); // NOLINT(cert-err34-c)

    //calculate
    int Pa = calculateP(a, Da);
    int Pb = calculateP(b, Db);

    //output
    printf("%d", Pa + Pb);

    return 0;
}
