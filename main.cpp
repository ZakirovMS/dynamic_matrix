#include <iostream>

int ** create (size_t m, size_t n);
void clean(int ** mtx, size_t m, size_t n);

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int ** mtx = create(M, N);
  clean (mtx, M, N);
}
