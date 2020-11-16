#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // NOLINT(cert-err34-c)

    //digits array
    int digitArray[3] = {0};
    int totalDigits = 0;
    while (n != 0) {
        digitArray[totalDigits] = n % 10;
        n /= 10;
        totalDigits++;
    }

    //output
    int hundredsPlace = digitArray[2];
    int tensPlace = digitArray[1];
    int onesPlace = digitArray[0];
    for (int i = 0; i < hundredsPlace; i++) {
        printf("B");
    }
    for (int i = 0; i < tensPlace; i++) {
        printf("S");
    }
    for (int i = 1; i <= onesPlace; i++) {
        printf("%d", i);
    }

    return 0;
}
