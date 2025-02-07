#include <stdio.h>
#define N 16

// Iterative ternary search: returns the index of key in arr[] or -1 if not found.
int ternarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        // Divide the range into three parts.
        int third = (right - left) / 3;
        int mid1 = left + third;
        int mid2 = right - third;
        
        if (arr[mid1] == key)
            return mid1;
        if (arr[mid2] == key)
            return mid2;
        
        if (key < arr[mid1])
            right = mid1 - 1;
        else if (key > arr[mid2])
            left = mid2 + 1;
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

int main(void) {
    // Create a sorted array of N elements.
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i * 2; 
    }

    // Search for each element in the array.
    // Each search runs in Θ(log₃ n) time.
    for (int i = 0; i < N; i++) {
        int pos = ternarySearch(arr, N, arr[i]);
        if (pos != -1) {
            printf("Element %d found at index %d\n", arr[i], pos);
        } else {
            printf("Element %d not found!\n", arr[i]);
        }
    }
    return 0;
}
