#ifndef MTX_HPP
#define MTX_HPP
#include <cstddef>
int ** create(size_t m, size_t n);
void clean(int ** mtx, size_t m);
void read(int ** mtx, size_t m, size_t n);
void write(const int * const * mtx, size_t m, size_t n);
#endif
