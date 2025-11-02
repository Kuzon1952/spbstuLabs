#include <stdio.h>
#include <time.h>
#include "strlen.h"

#define ITERATIONS 100000000
const char* test_string = "The People's Republic of Bangladesh lies in a corner of South Asia and in the eastern part of the ancient region of Bengal. ";

int main() {
    clock_t start, end;
    volatile int result;  // prevent optimization

    // Iterative
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = strlen_iterative(test_string);
    }
    end = clock();
    printf("Iterative strlen: %d\n", result);
    printf("Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Recursive
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = strlen_recursive(test_string);
    }
    end = clock();
    printf("Recursive strlen: %d\n", result);
    printf("Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
