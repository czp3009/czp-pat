#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // NOLINT(cert-err34-c)

    //input
    int a1Sum = 0,
            a2Parity = 1, a2Sum = 0, a2Exist = 0,
            a3Count = 0,
            a4Count = 0, a4Sum = 0,
            a5Max = 0;

    for (int i = 0; i < n; i++) {
        int current;
        scanf("%d", &current); // NOLINT(cert-err34-c)
        //process
        switch (current % 5) {
            case 0:
                if (current % 2 == 0) a1Sum += current;
                break;
            case 1:
                if (a2Parity) {
                    a2Parity = 0;
                    a2Sum += current;
                } else {
                    a2Parity = 1;
                    a2Sum -= current;
                }
                a2Exist = 1;
                break;
            case 2:
                a3Count++;
                break;
            case 3:
                a4Count++, a4Sum += current;
                break;
            case 4:
                if (current > a5Max) a5Max = current;
                break;
        }
    }

    //output
    char buffer[5][6] = {"N", "N", "N", "N", "N"};  //string size 6 for float
    if (a1Sum != 0) sprintf(buffer[0], "%d", a1Sum);
    if (a2Exist) sprintf(buffer[1], "%d", a2Sum);
    if (a3Count != 0) sprintf(buffer[2], "%d", a3Count);
    if (a4Count != 0) sprintf(buffer[3], "%.1f", (double) a4Sum / a4Count);
    if (a5Max != 0) sprintf(buffer[4], "%d", a5Max);
    for (int i = 0; i < 5; i++) {
        if (i != 0) printf(" ");
        printf("%s", buffer[i]);
    }

    return 0;
}
