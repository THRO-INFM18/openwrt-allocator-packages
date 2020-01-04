#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stddef.h>

/* sed -i 's/ malloc/ mymalloc/g' *.c */
void *mymalloc(size_t size);

/* sed -i 's/ calloc/ mycalloc/g' *.c */
void *mycalloc(size_t nmemb, size_t size);

/* sed -i 's/ realloc/ myrealloc/g' *.c */
void *myrealloc(void *ptr, size_t size);

#endif
