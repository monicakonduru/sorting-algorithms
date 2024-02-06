#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[minIndex], &arr[i]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));

    int size = 10;
    int arr[10];

    // Initialize array with random values
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;

    printf("Original array: ");
    printArray(arr, size);

    // Bubble Sort
    bubbleSort(arr, size);
    printf("\nBubble Sort: ");
    printArray(arr, size);

    // Selection Sort
    selectionSort(arr, size);
    printf("\nSelection Sort: ");
    printArray(arr, size);

    // Insertion Sort
    insertionSort(arr, size);
    printf("\nInsertion Sort: ");
    printArray(arr, size);

   

    

    return 0;
}