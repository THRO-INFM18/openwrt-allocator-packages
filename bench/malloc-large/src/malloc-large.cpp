// Benchmark supplied by Danila Kutenin (danlark1 @github) and modified by Daan Leijen
#include <memory>
#include <thread>
#include <vector>

const size_t N = 5000;

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
