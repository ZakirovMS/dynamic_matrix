#ifndef MTX_HPP
#define MTX_HPP
#include <cstddef>
int ** create(size_t m, size_t n);
void clean(int ** mtx, size_t m);
void read(const int * const * mtx, size_t m, size_t n);
void write(int ** mtx, size_t m, size_t n);
struct Mtx
{
  Mtx(size_t m, size_t n);
  Mtx(int ** old_mtx, size_t m, size_t n);
  ~Mtx();

  void read(const int * const * mtx, size_t m, size_t n);
  void write(int ** mtx, size_t m, size_t n);

  size_t get_columns() const;
  size_t get_rows() const;
  void change_size(size_t new_m, size_t new_n);

  private:
    int **mtx_;
    size_t m_;
    size_t n_;
};
#endif
