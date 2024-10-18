#include "mtx.hpp"
#include <cstddef>

int ** create(size_t m, size_t n)
  {
    int ** mtx = new int * [m];
    size_t created = 0;
    try
    {
      for (; created < m; ++created)
        {
          mtx[created] = new int [n];
        }
    }
    catch(const std::bad_alloc &e)
      {
        clean(mtx, created);
        throw;
      }
    return mtx;
  }


void clean (int ** mtx, size_t m)
{
  for(size_t i = 0; i < m; ++i)
  {
    delete[]mtx[i];
  }

  delete[]mtx;
}
