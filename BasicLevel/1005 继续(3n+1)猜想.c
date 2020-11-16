#include <stdio.h>

#define PROCESSED -1
#define CHECK_NEEDED 1
#define NO_DATA 0

int main() {
    int k;
    scanf("%d", &k); // NOLINT(cert-err34-c)
    //-1 for processed, 1 for check needed, 0 for no data
    //init with no data
    int numberAxis[101] = {NO_DATA};
    for (int i = 0; i < k; i++) {
        int n;
        scanf("%d", &n); // NOLINT(cert-err34-c)
        numberAxis[n] = CHECK_NEEDED;
    }

    //process all number
    //current number is i
    for (int i = 1; i < 101; i++) {
        if (numberAxis[i] != CHECK_NEEDED) continue;

        //3n+1
        int temp = i;
        while (temp != 1) {
            if (temp % 2 == 0) {
                temp /= 2;
            } else {
                temp = (3 * temp + 1) / 2;
            }
            //exceed number axis limit
            if (temp > 100) continue;
            //this number already checked
            if (numberAxis[temp] == PROCESSED) break;
            //set this number to checked status
            numberAxis[temp] = PROCESSED;
        }
    }

    //output
    int isFirst = 1;
    for (int i = 100; i > 0; i--) {
        if (numberAxis[i] == CHECK_NEEDED) {
            if (isFirst) {
                isFirst = 0;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }

    return 0;
}
