#include <iostream>
#include "mtx.hpp"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;

  if (!std::cin)
  {
    return 1;
  }

  int ** mtx = create(M, N);
  read(mtx, M, N);
  write(mtx, M, N);

  clean(mtx, M);
}
