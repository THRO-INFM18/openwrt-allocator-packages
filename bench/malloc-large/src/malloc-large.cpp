// Benchmark supplied by Danila Kutenin (danlark1 @github) and modified by Daan Leijen
#include <memory>
#include <thread>
#include <vector>

const size_t N = 5000;

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

void Foo() {
    for (size_t i = 0; i < N; ++i) {
        size_t sz = 1ull << 21;
        log_size(sz, "new");
        std::unique_ptr<char[]> a(new char[sz]);
        for(size_t k = 0; k < sz; k++) { a[k] = 'x'; }
    }
}

int main() {
    std::vector<std::thread> thrs;
    for (size_t i = 0; i < 1; ++i) {
        thrs.emplace_back(Foo);
    }
    for (auto&& thr : thrs) {
        thr.join();
    }
    return 0;
}
