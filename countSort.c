#include <stdio.h>
#define MAX 100

void countSort(int arr[], int n) {
    int output[100], count[MAX] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i < MAX; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n;

    printf("Enter number of elements (0–99): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original ");
    printArray(arr, n);

    countSort(arr, n);

    printf("Sorted ");
    printArray(arr, n);

    return 0;
}