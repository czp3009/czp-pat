#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // NOLINT(cert-err34-c)

    int count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        count++;
    }

    printf("%d", count);
    return 0;
}
