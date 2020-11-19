#include <stdio.h>
#include <stdlib.h>

int l, h;

struct Student {
    int number;
    int moralScore;
    int abilityScore;
};

int getStudentCategory(struct Student *student) {
    if (student->moralScore >= h && student->abilityScore >= h) {
        return 1;
    } else if (student->abilityScore < h && student->moralScore >= h) {
        return 2;
    } else if (student->moralScore < h && student->abilityScore < h && student->moralScore >= student->abilityScore) {
        return 3;
    } else {
        return 4;
    }
}

int comparer(const void *a, const void *b) {
    struct Student *student1 = (struct Student *) a;
    struct Student *student2 = (struct Student *) b;
    int student1Category = getStudentCategory(student1);
    int student2Category = getStudentCategory(student2);

    if (student1Category != student2Category) return student1Category - student2Category;

    int compareResult = student2->moralScore + student2->abilityScore - student1->moralScore - student1->abilityScore;
    if (compareResult == 0) compareResult = student2->moralScore - student1->moralScore;
    if (compareResult == 0) compareResult = student1->number - student2->number;
    return compareResult;
}

int main() {
    int n;
    scanf("%d %d %d", &n, &l, &h); // NOLINT(cert-err34-c)

    //input
    int m = 0;
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        struct Student student;
        scanf("%d %d %d", &student.number, &student.moralScore, &student.abilityScore); // NOLINT(cert-err34-c)
        if (student.moralScore < l || student.abilityScore < l) continue;
        students[m] = student;
        m++;
    }

    //sort
    qsort(students, m, sizeof(struct Student), comparer);

    //output
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        struct Student *current = &students[i]; //avoid copy
        printf("%d %d %d\n", current->number, current->moralScore, current->abilityScore);
    }

    return 0;
}
