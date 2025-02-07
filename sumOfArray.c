/*
Anish KC
CSE 3318
02/06/2025
*/
#include <stdio.h>

// Theta(n) time complexity
int main()
{
    int arr[] = {1, 2, 3, 4, 5}; // Array of 5 elements C1

    int n = 5, sum = 0, i = 0; // Initialize variables C2, C3, C4

    while (i < n) // Loop C5
    {
        sum += arr[i]; // Add current element to sum C6
        i++;           // i Increment C7
    }
    printf("Sum of array is: %d\n", sum); // Print sum C8
    return 0;                             // Return C9
}