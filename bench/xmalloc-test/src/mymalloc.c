#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "mymalloc.h"

static void log_size(size_t size, char *name) {
    static size_t sum = 0;
    static size_t max = 0;
    static size_t min = 0xEFFFFFFF;
    static size_t count_small = 0;
    static size_t count_large = 0;
    static size_t count_huge = 0;

    sum += size;

    if(size < min)
        min = size;
    if(size > max)
        max = size;

    if(size <= 2 * 1024)
        count_small++;
    else if(size <= 1 * 1024 * 1024)
        count_large++;
    else
        count_huge++;

    fprintf(stderr,
        "%s(): size = %d, sum = %d, max = %d, min = %d, small = %d, large = %d, huge = %d\n",
        name, size, sum, max, min, count_small, count_large, count_huge);
}

void *mymalloc(size_t size){
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
