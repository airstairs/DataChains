#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 333333333

int main() {
    clock_t start_time = clock();

    // Allocate a single contiguous block of memory
    int *arr = (int *)malloc(LIMIT * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < LIMIT; i++) {
        arr[i] = i;
    }

    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("%d variables created in %.2f seconds\n", LIMIT, cpu_time_used);
    
    // Print first three numbers added
    printf("First 3 numbers: %d, %d, %d\n", arr[0], arr[1], arr[2]);
    
    // Print last three numbers added
    printf("Last 3 numbers: %d, %d, %d\n", arr[LIMIT - 3], arr[LIMIT - 2], arr[LIMIT - 1]);

    free(arr);
    return 0;
}


// run instructions
// gcc -O3 fixed_array.c -o fixed_array
// ./fixed_array