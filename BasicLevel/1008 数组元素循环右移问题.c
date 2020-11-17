#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // NOLINT(cert-err34-c)
    //input
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]); // NOLINT(cert-err34-c)
    }

    //output
    int offset = m % n;
    int startIndex = n - offset;
    int isFirst = 1;
    for (int i = startIndex; i < n; i++) {
        if (isFirst) {
            isFirst = 0;
        } else {
            printf(" ");
        }
        printf("%d", array[i]);
    }
    for (int i = 0; i < startIndex; i++) {
        if (isFirst) {
            isFirst = 0;
        } else {
            printf(" ");
        }
        printf("%d", array[i]);
    }

    return 0;
}
