#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void quicksort(int arr[], const size_t size) {
    // Base case
    if (size < 2) {
        return;
    }

    // Get pivot

    // Make random number
    srand(time(NULL));
    // Generate random index for pivot
    const size_t index = rand() % size;
    const int pivot = arr[index];

    // Get two subarrays
    int* less = (int*) malloc(size * sizeof(arr[0]));
    if (less == NULL) {
        printf("Error allocating Less subarray.\n");
        return;
    }
    int* greater = (int*) malloc(size * sizeof(arr[0]));
    if (greater == NULL) {
        printf("Error allocating Greater subarray. Deallocating Less and exiting...\n");
        free(less);
        return;
    }
    size_t less_index = 0;
    size_t greater_index = 0;

    // Allocate based on whether values in the array are greater than or less than
    // the pivot
    for (size_t i = 0; i < size; i++) {
        if (arr[i] < pivot) {
            less[less_index++] = arr[i];
        } else if (arr[i] > pivot) {
            greater[greater_index++] = arr[i];
        }
    }

    quicksort(less, less_index);
    quicksort(greater, greater_index);

    size_t n = 0;
    for (; n < less_index; n++) {
        arr[n] = less[n];
    }
    arr[n++] = pivot;
    for (int i = 0; n < size; n++) {
        arr[n] = greater[i++];
    }

    free(less);
    free(greater);
}

int main(void) {
    int ia[SIZE] = { 12, 44, 52, 9, 56 ,7, 64, 23, 11, 81, 94, 4, 27, 58, 0 };
    quicksort(ia, SIZE);
    for (size_t i = 0; i < SIZE; i++) {
        printf("%d ", ia[i]);
    }
    printf("\n");

    return 0;
}
