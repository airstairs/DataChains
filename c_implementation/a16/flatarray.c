#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Test with ~650 million variables (~3 GB)
    long long limit = 500000000LL; 
    
    printf("Attempting to allocate %lld integers (%.2f GB)...\n", limit, (limit * 4.0) / (1024 * 1024 * 1024));
    
    clock_t start_time = clock();

    int *arr = (int *)malloc(limit * sizeof(int));
    if (arr == NULL) {
        printf("Allocation failed! Too large for available RAM.\n");
        return 1;
    }

    // Populate the array with values
    for (long long i = 0; i < limit; i++) {
        arr[i] = (int)i;
    }

    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Success! Allocated and populated (%lld integers) in %.2f seconds.\n",limit, cpu_time_used);
    
    // Print first three numbers added
    printf("First 3 numbers: %d, %d, %d\n", arr[0], arr[1], arr[2]);
    
    // Print last three numbers added
    printf("Last 3 numbers: %d, %d, %d\n", arr[limit - 3], arr[limit - 2], arr[limit - 1]);

    free(arr);
    return 0;
}

/* 
 * HOW TO COMPILE AND RUN IN TERMUX:
 * 
 * 1. Compile the code with compiler optimizations enabled (-O3):
 *    gcc -O3 flatarray.c -o flatarray
 * 
 * 2. Execute the compiled binary:
 *    ./flatarray
 */
