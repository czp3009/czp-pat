#include <stdio.h>

int main() {
    //input
    char a[1001];
    int b;
    scanf("%s %d", a, &b); // NOLINT(cert-err34-c)

    //calculate and output
    //simulation BigDecimal division
    int currentDividend = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        currentDividend = currentDividend * 10 + a[i] - '0';
        int currentResult = currentDividend / b;
        if (i != 0 || currentResult != 0 || a[i + 1] == '\0') { //skip first 0
            printf("%d", currentResult);
        }
        currentDividend -= currentResult * b;
    }
    printf(" %d", currentDividend);

    return 0;
}
