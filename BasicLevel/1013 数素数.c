#include <stdio.h>
#include <math.h>

#define NUMBER_AXIS_LENGTH 104730   //no.10000 prime number is 104729
#define NOT_CHECKED 0
#define IS_PRIME_NUMBER 1
#define NOT_PRIME_NUMBER -1

int isPrimeNumber(int number, const int *numberAxis) {
    int upperLimit = sqrt(number); // NOLINT(cppcoreguidelines-narrowing-conversions)
    for (int current = 2; current <= upperLimit; current++) {
        if (numberAxis[current] != IS_PRIME_NUMBER) continue;
        if (number % current == 0) return 0;
    }
    return 1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n); // NOLINT(cert-err34-c)

    //Euler
    int numberAxis[NUMBER_AXIS_LENGTH] = {0};
    int primeNumberIndex = 0;
    int startPrimeNumber = 2;
    int endPrimeNumber = 2;
    for (int current = 2; current < NUMBER_AXIS_LENGTH; current++) {
        if (numberAxis[current] != NOT_CHECKED) continue;
        if (isPrimeNumber(current, numberAxis)) {
            numberAxis[current] = IS_PRIME_NUMBER;
            primeNumberIndex++;
            if (primeNumberIndex == m) startPrimeNumber = current;
            if (primeNumberIndex == n) {
                endPrimeNumber = current;
                break;
            }
            for (int j = 2; current * j < NUMBER_AXIS_LENGTH; j++) {
                numberAxis[current * j] = NOT_PRIME_NUMBER;
            }
        } else {
            numberAxis[current] = NOT_PRIME_NUMBER;
        }
    }

    //output
    int lineIndex = 0;
    for (int current = startPrimeNumber; current <= endPrimeNumber; current++) {
        if (numberAxis[current] == IS_PRIME_NUMBER) {
            if (lineIndex != 0) printf(" ");
            printf("%d", current);
            if (lineIndex == 9) {
                lineIndex = 0;
                printf("\n");
            } else {
                lineIndex++;
            }
        }
    }

    return 0;
}
