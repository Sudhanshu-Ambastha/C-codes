#include <stdio.h>

void convert_to_words(int n);

void print_unit(int n) {
    char *units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    printf("%s ", units[n]);
}

void print_tens(int n) {
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    printf("%s ", tens[n]);
}

void print_teens(int n) {
    char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    printf("%s ", teens[n - 10]);
}

void convert_to_words(int n) {
    if (n >= 1000000000) {
        printf("Number exceeds limit!\n");
        return;
    }

    if (n == 0) {
        printf("Zero\n");
        return;
    }

    if (n >= 1000000) {
        convert_to_words(n / 1000000);
        printf("Million ");
        n = n % 1000000;
    }

    if (n >= 1000) {
        convert_to_words(n / 1000);
        printf("Thousand ");
        n = n % 1000;
    }

    if (n >= 100) {
        convert_to_words(n / 100);
        printf("Hundred ");
        n = n % 100;
    }

    if (n >= 20) {
        print_tens(n / 10);
        n = n % 10;
    } else if (n >= 10) {
        print_teens(n);
        return;
    }

    if (n > 0 && n < 10) {
        print_unit(n);
    }
}

int main() {
    int num;
    printf("Enter a number (0 to 1 billion): ");
    scanf("%d", &num);

    if (num >= 1000000000) {
        printf("Number exceeds 1 billion!\n");
    } else {
        convert_to_words(num);
        printf("\n");
    }

    return 0;
}