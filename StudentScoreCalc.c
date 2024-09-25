#include <stdio.h>

int main() {
    int i = 0, j, marks[5];
    float total, average;
    char grade;

    do {
        total = 0;

        printf("Enter marks for student %d in 5 subjects:\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[j]);
            total += marks[j];
        }

        average = total / 5.0;

        if (average >= 80) {
            grade = 'A';
        } else if (average >= 75) {
            grade = 'B';
        } else if (average >= 55) {
            grade = 'C';
        } else {
            grade = 'D';
        }

        printf("Student %d - Average Marks: %.2f, Grade: %c\n", i + 1, average, grade);
        i++;

    } while (i < 30); 

    return 0;
}