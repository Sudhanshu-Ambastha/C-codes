#include <stdio.h>

#define MAX 100

void bucketSort(int arr[], int n) {
    int bucket[MAX] = {0};

    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;

    int idx = 0;
    for (int i = 0; i < MAX; i++) {
        while (bucket[i]-- > 0)
            arr[idx++] = i;
    }
}

void printArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Element %d (0–99): ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted ");
    printArray(arr, n);

    return 0;
}