#include <stdio.h>

struct Record {
    char name[11];
    char number[11];
    int score;
};

int main() {
    int n;
    scanf("%d", &n); // NOLINT(cert-err34-c)

    //input
    struct Record records[n];
    for (int i = 0; i < n; i++) {
        struct Record record;
        scanf("%s %s %d", record.name, record.number, &record.score); // NOLINT(cert-err34-c)
        records[i] = record;
    }

    //find max and min
    struct Record maxRecord = records[0];
    struct Record minRecord = records[0];
    for (int i = 1; i < n; i++) {
        struct Record currentRecord = records[i];
        if (currentRecord.score > maxRecord.score) {
            maxRecord = currentRecord;
        } else if (currentRecord.score < minRecord.score) {
            minRecord = currentRecord;
        }
    }

    //output
    printf("%s %s\n", maxRecord.name, maxRecord.number);
    printf("%s %s\n", minRecord.name, minRecord.number);

    return 0;
}
