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

Mtx::Mtx(size_t m, size_t n)
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

  mtx_ = mtx;
  m_ = m;
  n_ = n;
}

Mtx::Mtx(int ** mtx, size_t m, size_t n)
{
  int ** new_mtx = new int * [m];
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

  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      new_mtx[m][n] = mtx[m][n];
    }
  }

  mtx_ = new_mtx;
}

Mtx::~Mtx()
{
  for(size_t i = 0; i < m_; ++i)
  {
    delete[] mtx_[i];
  }

  delete[] mtx_;
}

void Mtx::read(const int * const * mtx, size_t m, size_t n)
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

void Mtx::write(int ** mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}

size_t Mtx::get_columns() const
{
  return m_;
}

size_t Mtx::get_rows() const
{
  return n_;
}

void Mtx::change_size(size_t new_m, size_t new_n)
{
  size_t columns = new_m < m_ ? new_m : m_;
  size_t rows = new_n < n_ ? new_n : n_;
  int ** chsize_mtx = new int * [columns];
  size_t counter = 0;
  try
  {
    for (; counter < columns; ++counter)
    {
      chsize_mtx[counter] = new int[rows];
    }
  }
  catch(const std::bad_alloc &e)
  {
    clean(chsize_mtx, counter);
    throw;
  }

  for (size_t i = 0; i < columns; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      chsize_mtx[columns][rows] = mtx_[columns][rows];
    }
  }

  mtx_ = chsize_mtx;
  m_ = new_m;
  n_ = new_n;
}
