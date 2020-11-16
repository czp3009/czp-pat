#include <stdio.h>

int isCorrect(const char line[102]) {
    int indexOfP = -1;
    int indexOfT = -1;

    int i;
    for (i = 0;; i++) {
        char currentChar = line[i];
        if (currentChar == '\0') break;

        if (currentChar != 'P' && currentChar != 'A' && currentChar != 'T') return 0;

        if (indexOfP == -1 && indexOfT == -1) { //prefix
            if (currentChar == 'P') {
                indexOfP = i;
                continue;
            }
        } else if (indexOfP != -1 && indexOfT == -1) { //infix
            if (currentChar == 'T') {
                indexOfT = i;
                continue;
            }
        }
        //suffix
        if (currentChar != 'A') return 0;
    }

    //no P or no T
    if (indexOfP == -1 || indexOfT == -1) return 0;

    int prefixA = indexOfP;
    int infixA = indexOfT - indexOfP - 1;
    int suffixA = i - 1 - indexOfT;

    //no infix A
    if (infixA == 0) return 0;

    //countOfPrefixA * countOfInfixA == countOfSuffixA
    return prefixA * infixA == suffixA;
}

int main() {
    int n;
    scanf("%d\n", &n); // NOLINT(cert-err34-c)

    for (int i = 0; i < n; i++) {
        char currentLine[102];
        gets(currentLine);
        if (isCorrect(currentLine)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
