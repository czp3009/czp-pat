#include <stdio.h>
#include <string.h>

char *dayTable[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    char string1[61], string2[61], string3[61], string4[61];
    gets(string1);
    gets(string2);
    gets(string3);
    gets(string4);

    //process 1 and 2
    int day;
    int hour;
    int i1 = 0;
    for (;; i1++) {
        char current = string1[i1];
        if (current == string2[i1] && (current >= 'A' && current <= 'G')) {
            day = current - 'A';
            break;
        }
    }
    i1++;
    for (;; i1++) {
        char current = string1[i1];
        if (current == string2[i1] && ((current >= '0' && current <= '9') || (current >= 'A' && current <= 'N'))) {
            if (current <= '9') {
                hour = current - '0';
            } else {
                hour = 10 + current - 'A';
            }
            break;
        }
    }

    //process 3 and 4
    int minute;
    for (int i3 = 0;; i3++) {
        char current = string3[i3];
        if (current == string4[i3] && ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z'))) {
            minute = i3;
            break;
        }
    }

    //output
    printf("%s %02d:%02d", dayTable[day], hour, minute);

    return 0;
}
