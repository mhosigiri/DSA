#include <stdio.h>
#include <stdlib.h>
#define N 16
// Time complexity: O(nlog2n)
//  Merge two sorted subarrays: arr[left..mid-1] and arr[mid..right-1]
void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    int size = right - left;
    int *temp = (int *)malloc(size * sizeof(int));

    // Merge the two subarrays into temp[]
    while (i < mid && j < right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i < mid)
        temp[k++] = arr[i++];
    while (j < right)
        temp[k++] = arr[j++];

    // Copy sorted subarray back into arr[]
    for (i = left, k = 0; i < right; i++, k++)
    {
        arr[i] = temp[k];
    }
    free(temp);
}

int main(void)
{
    // Example array to be sorted.
    int arr[N] = {23, 12, 45, 6, 19, 34, 8, 56, 17, 3, 28, 41, 10, 5, 29, 15};
    int width, i;

    // Iterative merge sort: start with subarrays of width 1 and double each pass.
    for (width = 1; width < N; width = 2 * width)
    { // Outer loop: O(log₂N) passes.
        for (i = 0; i < N; i = i + 2 * width)
        { // Inner loop: processes O(n/width) merges.
            int left = i;
            int mid = (i + width < N) ? i + width : N;
            int right = (i + 2 * width < N) ? i + 2 * width : N;
            merge(arr, left, mid, right);
        }
    }

    // Print the sorted array.
    printf("Sorted array by Merge Sort: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
