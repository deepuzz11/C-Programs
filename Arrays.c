//Task 1: Print the array elements and their addresses

#include <stdio.h>

void printArrayElementsAndAddresses(int arr[], int size) {
    printf("Array elements and their addresses:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d \t Address: %p\n", i, arr[i], &arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArrayElementsAndAddresses(arr, size);

    return 0;
}

//Task 2: Find the largest and smallest element of an array

#include <stdio.h>
#include <limits.h>

void findLargestAndSmallest(int arr[], int size) {
    int max = INT_MIN, min = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Largest element: %d\n", max);
    printf("Smallest element: %d\n\n", min);
}

int main() {
    int arr[] = {3, 7, 1, 9, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    findLargestAndSmallest(arr, size);

    return 0;
}

//Task 3: Find the number of elements in an array

#include <stdio.h>

int countElements(int arr[]) {
    return sizeof(arr) / sizeof(arr[0]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = countElements(arr);

    printf("Number of elements in array: %d\n\n", size);

    return 0;
}

//Task 4: Print the odd and even numbers in a given array

#include <stdio.h>

void printOddAndEvenNumbers(int arr[], int size) {
    printf("Odd numbers in the array: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("Even numbers in the array: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printOddAndEvenNumbers(arr, size);

    return 0;
}

//Task 5: Find Maximum Difference Between Two Elements in an Array

#include <stdio.h>
#include <stdlib.h>

int findMaxDifference(int arr[], int size) {
    int maxDiff = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int diff = abs(arr[i] - arr[j]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
    }

    return maxDiff;
}

int main() {
    int arr[] = {7, 2, 3, 10, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxDifference = findMaxDifference(arr, size);

    printf("Maximum difference between two elements in the array: %d\n\n", maxDifference);

    return 0;
}

//Task 6: Program to reverse the array elements

#include <stdio.h>

void reverseArray(int arr[], int size) {
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Reversed array: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);

    return 0;
}

//Task 7: Print the square of array elements

#include <stdio.h>

void printSquareOfElements(int arr[], int size) {
    printf("Array elements and their squares:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ^ 2 = %d\n", arr[i], arr[i] * arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printSquareOfElements(arr, size);

    return 0;
}

