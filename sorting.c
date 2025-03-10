#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INSERTION_SORT 1
#define QUICK_SORT 2
#define M_ARR_SIZE 4000

void generateRandomFiles();
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void readFileAndSort(const char *filename, int algorithm);
void displaySortedArray(int arr[], int n);
double measureSortingTime(int arr[], int n, int algorithm);

void generateRandomFiles()
{
    FILE *fp20, *fp100, *fp1000, *fp4000;
    int i;

    fp20 = fopen("arr20.txt", "w");
    fp100 = fopen("arr100.txt", "w");
    fp1000 = fopen("arr1000.txt", "w");
    fp4000 = fopen("arr4000.txt", "w");

    if (fp20 == NULL || fp100 == NULL || fp1000 == NULL || fp4000 == NULL)
    {
        printf("Error in opening file.\n");
        exit(1);
    }

    for (i = 0; i < 20; i++)
    {
        fprintf(fp20, "%d\n", rand() % 6001);

        fprintf(fp100, "%d\n", rand() % 6001);
        fprintf(fp1000, "%d\n", rand() % 6001);
        fprintf(fp4000, "%d\n", rand() % 6001);
    }

    for (i = 20; i < 100; i++)
    {
        fprintf(fp100, "%d\n", rand() % 6001);
        fprintf(fp1000, "%d\n", rand() % 6001);
        fprintf(fp4000, "%d\n", rand() % 6001);
    }
    for (i = 100; i < 1000; i++)
    {
        fprintf(fp1000, "%d\n", rand() % 6001);
        fprintf(fp4000, "%d\n", rand() % 6001);
    }
    for (i = 1000; i < 4000; i++)
    {
        fprintf(fp4000, "%d\n", rand() % 6001);
    }

    fclose(fp20);
    fclose(fp100);
    fclose(fp1000);
    fclose(fp4000);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
void readFileAndSort(const char *filename, int algorithm)
{
    FILE *fp;
    int arr[M_ARR_SIZE], n = 0;
    int value;
    char algorithm_name[20];

    if (algorithm == INSERTION_SORT)
    {
        strcpy(algorithm_name, "Insertion Sort");
    }
    else
    {
        strcpy(algorithm_name, "Quick Sort");
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error in opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%d", &value) != EOF)
    {
        arr[n++] = value;
    }
    fclose(fp);

    int arr_copy[M_ARR_SIZE];
    memcpy(arr_copy, arr, n * sizeof(int));

    double time_ms = measureSortingTime(arr, n, algorithm);

    int array_size = 0;
    if (strstr(filename, "20") != NULL)
    {
        array_size = 20;
    }
    else if (strstr(filename, "100") != NULL)
    {
        array_size = 100;
    }
    else if (strstr(filename, "1000") != NULL)
    {
        array_size = 1000;
    }
    else if (strstr(filename, "4000") != NULL)
    {
        array_size = 4000;
    }

    printf("Sorted %d elements (%s) from %s: %.3f (Time taken in ms)\n",
           array_size, algorithm_name, filename, time_ms);
}
double measureSortingTime(int arr[], int n, int algorithm)
{
    clock_t start, end;
    double time_ms;

    start = clock();

    if (algorithm == INSERTION_SORT)
    {
        insertionSort(arr, n);
    }
    else
    {
        quickSort(arr, 0, n - 1);
    }

    end = clock();

    time_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    return time_ms;
}

void displaySortedArray(int arr[], int n)
{
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand((unsigned int)time(NULL));

    generateRandomFiles();
    printf("Random files generated successfully.\n");

    printf("Insertion sort\n");
    readFileAndSort("arr20.txt", INSERTION_SORT);
    readFileAndSort("arr100.txt", INSERTION_SORT);
    readFileAndSort("arr1000.txt", INSERTION_SORT);
    readFileAndSort("arr4000.txt", INSERTION_SORT);

    printf("\nQuick sort\n");
    readFileAndSort("arr20.txt", QUICK_SORT);
    readFileAndSort("arr100.txt", QUICK_SORT);
    readFileAndSort("arr1000.txt", QUICK_SORT);
    readFileAndSort("arr4000.txt", QUICK_SORT);

    return 0;
}