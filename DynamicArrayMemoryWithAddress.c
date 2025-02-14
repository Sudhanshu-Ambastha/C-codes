#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: %d, Address: %p\n", i + 1, arr[i], (void *)&arr[i]);
    }

    printf("\nTotal Memory Allocated: %lu bytes\n", n * sizeof(int));

    free(arr);

    return 0;
}
