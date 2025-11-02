#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>

#define ITERATIONS 10000000
const char* test_string = "The People's Republic of Bangladesh lies in a corner of South Asia and in the eastern part of the ancient region of Bengal. ";
int main() {
    void *handle;
    int (*iter)(const char*);
    int (*recur)(const char*);
    char *error;

    handle = dlopen("./libstrlen.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    iter = dlsym(handle, "strlen_iterative");
    recur = dlsym(handle, "strlen_recursive");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < ITERATIONS; i++) {
        result = iter(test_string);
    }
    clock_t end = clock();
    printf("Dlopen Iterative strlen: %d\n", result);
    printf("Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = recur(test_string);
    }
    end = clock();
    printf("Dlopen Recursive strlen: %d\n", result);
    printf("Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    dlclose(handle);
    return 0;
}
