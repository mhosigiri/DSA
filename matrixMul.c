#include <stdio.h>
// Time complexity: O(n³)
// Matrix multiplication

int main()
{
    int n = 4;           // c₁           1 time
    int A[4][4] = {{1}}; // c₂  Array Initialization         1 time
    int B[4][4] = {{1}}; // c₃  Array Initialization         1 time
    int C[4][4] = {{0}}; // c₄  Array Initialization         1 time

    for (int i = 0; i < n; i++)
    { // c₅          n+1 times
        for (int j = 0; j < n; j++)
        { // c₆        n(n+1) times
            for (int k = 0; k < n; k++)
            {                                 // c₇      n²(n+1) times
                C[i][j] += A[i][k] * B[k][j]; // c₈  n³ times
            }
        }
    }
    return 0;
}