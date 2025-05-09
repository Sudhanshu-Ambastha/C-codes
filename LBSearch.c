#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size. Exiting.\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }
    printf("Enter the elements of the array (separated by spaces):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int target;
    int index;
    printf("Enter the number to search using Linear Search: ");
    scanf("%d", &target);
    index = linearSearch(arr, n, target);
    if (index != -1) {
        printf("Linear Search: Element found at index %d\n", index);
    } else {
        printf("Linear Search: Element not found\n");
    }
    printf("Enter the number to search using Binary Search: ");
    scanf("%d", &target);
    index = binarySearch(arr, n, target);
    if (index != -1) {
        printf("Binary Search: Element found at index %d\n", index);
    } else {
        printf("Binary Search: Element not found\n");
    }
    free(arr);
    return 0;
}
