#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons) {
    *comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) (*comparisons)++; // Count the last comparison that fails
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int comparisonsInsertion, comparisonsSelection;

    printf("Original array: ");
    printArray(arr1, n);

    insertionSort(arr1, n, &comparisonsInsertion);
    printf("Sorted array using Insertion Sort: ");
    printArray(arr1, n);
    printf("Number of comparisons in Insertion Sort: %d\n\n", comparisonsInsertion);

    selectionSort(arr2, n, &comparisonsSelection);
    printf("Sorted array using Selection Sort: ");
    printArray(arr2, n);
    printf("Number of comparisons in Selection Sort: %d\n", comparisonsSelection);

    return 0;
}
