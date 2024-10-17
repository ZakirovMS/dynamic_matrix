#ifndef "MTX_H"
#define "MTX_H"
int ** create (size_t m, size_t n);
void clean(int ** mtx, size_t m, size_t n);
void read (int ** mtx, size_t m, size_t n);
void write (const int * const * mtx size_t m, size_t n);
#endif
