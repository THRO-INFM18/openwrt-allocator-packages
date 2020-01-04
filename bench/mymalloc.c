#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
#include <atomic>
#include <iostream>
using namespace std;
#else
#include <stdatomic.h>
#include <stdio.h>
#endif

#include "mymalloc.h"

#define SMALL_MAX   2 * 1024
#define LARGE_MAX   1 * 1024 * 1024

static void log_size(size_t size, char *name) {
    static atomic_size_t max = 0;
    static atomic_size_t min = UINT_MAX;
    static atomic_llong sum = 0;
    static atomic_llong count_small = 0;
    static atomic_llong count_large = 0;
    static atomic_llong count_huge = 0;

    sum += (long long) size;

    if(size < min)
        min = size;
    if(size > max)
        max = size;

    if(size <= (size_t) (SMALL_MAX))
        count_small++;
    else if(size <= (size_t) (LARGE_MAX))
        count_large++;
    else
        count_huge++;

#ifdef __cplusplus
    cerr << name << "(): " <<
        "size = " << size <<
        ", sum = " << sum <<
        ", max = " << max <<
        ", min = " << min <<
        ", small = ", count_small <<
        ", large = " << count_large <<
        ", huge = " << count_huge <<
        endl;
#else
    fprintf(stderr,
        "%s(): size = %d, sum = %d, max = %d, min = %d, small = %d, large = %d, huge = %d\n",
        name, size, sum, max, min, count_small, count_large, count_huge);
#endif
}

void *mymalloc(size_t size) {
    log_size(size, "malloc");
    return malloc(size);
}

void *mycalloc(size_t nmemb, size_t size) {
    log_size((nmemb != 0 ? nmemb : 1) * size, "calloc");
    return calloc(nmemb, size);
}

void *myrealloc(void *ptr, size_t size) {
    log_size(size, "realloc");
    return realloc(ptr, size);
}
