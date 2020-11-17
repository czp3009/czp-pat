#include <stdio.h>

int main() {
    int coefficient, exponent;

    int isFirst = 1;
    while (scanf("%d %d", &coefficient, &exponent) != EOF) { // NOLINT(cert-err34-c)
        if (exponent == 0) continue;
        if (isFirst) {
            isFirst = 0;
        } else {
            printf(" ");
        }
        printf("%d %d", coefficient * exponent, exponent - 1);
    }

    //empty
    if (isFirst) {
        printf("0 0");
    }

    return 0;
}
