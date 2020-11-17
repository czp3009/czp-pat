#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t); // NOLINT(cert-err34-c)

    for (int i = 0; i < t; i++) {
        long a, b, c;
        scanf("%ld %ld %ld", &a, &b, &c); // NOLINT(cert-err34-c)
        printf("Case #%d: %s\n", i + 1, a + b > c ? "true" : "false");
    }

    return 0;
}
