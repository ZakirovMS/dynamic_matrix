#include <iostream>
#include "mtx.h"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int ** mtx = create(M, N);
  read(mtx, M, N);
  write(mtx, M, N);

  clean(mtx, M, N);
}
