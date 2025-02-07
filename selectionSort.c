#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *arr, int n)
{
    int i, j, min_idx;

    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d integer: \n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    selectionSort(arr, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}