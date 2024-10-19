#include "mtx.hpp"
#include <cstddef>
#include <iostream>

int ** create(size_t m, size_t n)
{
  int ** mtx = new int * [m];
  size_t counter = 0;

  try
  {
    for (; counter < m; ++counter)
    {
      mtx[counter] = new int[n];
    }
  }
  catch(const std::bad_alloc &e)
  {
    clean(mtx, counter);
    throw;
  }

  return mtx;
}


void clean(int ** mtx, size_t m)
{
  for(size_t i = 0; i < m; ++i)
  {
    delete[] mtx[i];
  }

  delete[] mtx;
}


void write(int ** mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      std::cin >> mtx[i][j];
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

      if ((j+1) != n)
      {
        std::cout << " ";
      }
      else
      {
        std::cout << "\n";
      }

    }
  }
}
