#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 10

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    
    int index = 0;
    for (int i = 0; i <= max; i++)
        while (count[i]-- > 0)
            arr[index++] = i;
    
    free(count);
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n], count[10] = {0};
        
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

void bucketSort(float arr[], int n) {
    float bucket[BUCKET_SIZE][n];
    int count[BUCKET_SIZE] = {0};
    
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_SIZE;
        bucket[index][count[index]++] = arr[i];
    }
    
    for (int i = 0; i < BUCKET_SIZE; i++)
        for (int j = 1; j < count[i]; j++) {
            float key = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++)
        for (int j = 0; j < count[i]; j++)
            arr[index++] = bucket[i][j];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printArrayFloat(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    float arr3[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    countingSort(arr1, n1);
    printf("Sorted array using Counting Sort: ");
    printArray(arr1, n1);
    
    radixSort(arr2, n1);
    printf("Sorted array using Radix Sort: ");
    printArray(arr2, n1);
    
    printf("Original float array: ");
    printArrayFloat(arr3, n2);
    
    bucketSort(arr3, n2);
    printf("Sorted array using Bucket Sort: ");
    printArrayFloat(arr3, n2);
    
    return 0;
}
