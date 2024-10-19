#include <iostream>
#include <exception>
#include "mtx.hpp"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;

  if (!std::cin)
  {
    std::cout << "The input is incorrect" << "\n";
    return 1;
  }

  int ** mtx = nullptr;
  try
  {
    int ** mtx = create(M, N);
  }
  catch(const std::bad_alloc &e)
  {
    std::cout << "Not enough memory" << "\n";
    return 1;
  }

  write(mtx, M, N);
  if (!std::cin)
  {
    std::cout << "The input is incorrect" << "\n";
    return 1;
  }

  read(mtx, M, N);
  clean(mtx, M);
}

