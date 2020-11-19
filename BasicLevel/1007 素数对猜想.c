#include <stdio.h>
#include <memory.h>
#include <math.h>

#define NOT_CHECKED 0
#define IS_PRIME_NUMBER 1
#define NOT_PRIME_NUMBER -1

int isPrimeNumber(int number, const int *numberAxis) {
    int upperLimit = sqrt(number); // NOLINT(cppcoreguidelines-narrowing-conversions)
    for (int i = 2; i <= upperLimit; i++) {
        if (numberAxis[i] != IS_PRIME_NUMBER) continue;
        if (number % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n); // NOLINT(cert-err34-c)

    //Euler
    int numberAxisLength = n + 1;
    int numberAxis[numberAxisLength];
    memset(numberAxis, NOT_CHECKED, sizeof(int) * numberAxisLength);
    for (int i = 2; i < numberAxisLength; i++) {
        if (numberAxis[i] != NOT_CHECKED) continue;
        if (isPrimeNumber(i, numberAxis)) {
            numberAxis[i] = IS_PRIME_NUMBER;
            for (int j = 2; i * j < numberAxisLength; j++) {
                numberAxis[i * j] = NOT_PRIME_NUMBER;
            }
        } else {
            numberAxis[i] = NOT_PRIME_NUMBER;
        }
    }

    //output
    int count = 0;
    for (int i = 4; i < numberAxisLength; i++) {
        if (numberAxis[i] == IS_PRIME_NUMBER && numberAxis[i - 2] == IS_PRIME_NUMBER) {
            count++;
            i++;    //skip next number
        }
    }
    printf("%d", count);

    return 0;
}
