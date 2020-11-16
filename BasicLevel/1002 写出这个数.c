#include <stdio.h>

char *pingYinTable[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    //calculate sum
    int sum = 0;
    while (1) {
        char currentInput = getchar(); // NOLINT(cppcoreguidelines-narrowing-conversions)
        if (currentInput == '\n' || currentInput == EOF) break;
        sum += currentInput - '0';
    }

    //get every digits
    int digitArray[1000] = {0};
    int totalDigits = 0;
    while (sum != 0) {
        digitArray[totalDigits] = sum % 10;
        sum /= 10;
        totalDigits++;
    }

    //output
    for (int i = totalDigits - 1; i >= 0; i--) {
        printf("%s", pingYinTable[digitArray[i]]);
        if (i != 0) printf(" ");
    }

    return 0;
}
