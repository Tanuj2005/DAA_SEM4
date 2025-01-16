#include <stdio.h>

int comparisonCount = 0;

int iterativeBinarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        comparisonCount++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1;
    comparisonCount++;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, right, target);
    return recursiveBinarySearch(arr, left, mid - 1, target);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    printf("Iterative Binary Search:\n");
    comparisonCount = 0;
    int iterativeResult = iterativeBinarySearch(arr, n, target);
    if (iterativeResult != -1)
        printf("Element found at index %d\n", iterativeResult);
    else
        printf("Element not found\n");
    printf("Number of comparisons: %d\n", comparisonCount);

    printf("\nRecursive Binary Search:\n");
    comparisonCount = 0;
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, target);
    if (recursiveResult != -1)
        printf("Element found at index %d\n", recursiveResult);
    else
        printf("Element not found\n");
    printf("Number of comparisons: %d\n", comparisonCount);

    return 0;
}
