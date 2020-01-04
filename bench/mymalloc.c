#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* Static vars are thread safe in C++11 and above */
#ifdef __cplusplus
#define SIZE_T size_t
#define LLONG long long
#else
#include <stdatomic.h>
#define SIZE_T atomic_size_t
#define LLONG atomic_llong
#endif

#include "mymalloc.h"

static const size_t small_max = 2 * 1024;
static const size_t large_max = 1 * 1024 * 1024;

static void log_size(size_t size, const char *name) {
    static SIZE_T max = 0;
    static SIZE_T min = UINT_MAX;
    static LLONG sum = 0;
    static LLONG count_small = 0;
    static LLONG count_large = 0;
    static LLONG count_huge = 0;

    sum += (long long) size;

    if(size < min)
        min = size;
    if(size > max)
        max = size;

    if(size <= small_max)
        count_small++;
    else if(size <= large_max)
        count_large++;
    else
        count_huge++;

    fprintf(stderr,
        "%s(): size = %d, sum = %d, max = %d, min = %d, small = %d, large = %d, huge = %d\n",
        name, size, sum, max, min, count_small, count_large, count_huge);
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
