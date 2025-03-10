#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quickSelectThirdSmallest(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void readFileIntoArray(const char *filename, int arr[], int *size);

#define M_ARR_SIZE 4000

void readFileIntoArray(const char *filename, int arr[], int *size)
{
    FILE *fp;
    int value;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open the file %s\n", filename);
        exit(1);
    }
    *size = 0;
    while (fscanf(fp, "%d", &value) == 1 && *size < M_ARR_SIZE)
    {
        arr[(*size)++] = value;
    }
    fclose(fp);
}

int quickSelectThirdSmallest(int arr[], int low, int high)
{
    int k = 2;
    while (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k)
        {
            high = pivotIndex - 1;
        }
        else
        {
            low = pivotIndex + 1;
        }
    }
    return -1;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int main()
{
    int arr[M_ARR_SIZE];
    int size = 0;

    readFileIntoArray("arr4000.txt", arr, &size);
    if (size < 3)
    {
        printf("The input file does not contain at least 3 elements.\n");
        return 1;
    }
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    int third_smallest = quickSelectThirdSmallest(arr, 0, size - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) / 1e6;
    printf("3rd smallest number: %d\n", third_smallest);
    printf("Time taken: %.3lf ms\n", time_taken);
    return 0;
}