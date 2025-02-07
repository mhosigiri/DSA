/*
Anish KC
CSE 3318
02/06/2025
*/
#include <stdio.h>
// Time complexity: O(n^2)
void insertion_sort(int A[], int n)
{
    int j, key, i;

    for (j = 1; j < n; j++)
    {               // Line 1: Loop from the second element to the last
        key = A[j]; // Line 2: Store A[j] as key
        i = j - 1;  // Line 4: Initialize i to track the previous element

        while (i >= 0 && A[i] > key)
        {                    // Line 5: Shift elements greater than key
            A[i + 1] = A[i]; // Line 6: Move A[i] to A[i+1]
            i = i - 1;       // Line 7: Decrement i
        }
        A[i + 1] = key; // Line 8: Insert key into the correct position
    }
}

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // Worst-case: reverse sorted
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    print_array(A, n);

    insertion_sort(A, n);

    printf("Sorted array: ");
    print_array(A, n);

    return 0;
}
