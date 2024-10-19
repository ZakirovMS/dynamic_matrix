#include "mtx.hpp"
#include <cstddef>
#include <iostream>

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
    clean(mtx, m);
    throw;
  }

  return mtx;
}


void clean(int ** mtx, size_t m)
{
  for(size_t i = 0; i < m; ++i)
  {
    delete[]mtx[i];
  }

  delete[]mtx;
}


void write(int ** mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      std::cin >> mtx[j][i];
    }
  }
}


void read(const int * const * mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++ j)
    {
      std::cout << mtx[i][j];
    }
    std:: cout << "\n";
  }
}
