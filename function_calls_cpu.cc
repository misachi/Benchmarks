#include <iostream>
#include <ctime>

int foo(int n) {
  // Some algorithm
  return n * 2;
}

int main() {
  std::clock_t start, end;
  size_t size = 100000;
  long j;
  std::cout << "Start loop with function calls"<< std::endl;
  start = std::clock();
  for (size_t i=0; i < size; ++i)
    j = foo(i);

  end = std::clock();

  std::cout << "Fcalls running time -> " <<1000.0 * (end - start)/CLOCKS_PER_SEC << std::endl;


  std::cout << std::endl;

  std::cout << "Start loop no function calls"<< std::endl;

  start = std::clock();
  for (size_t i=0; i < size; ++i) {
    j = i * 3;
  }
  end = std::clock();

  std::cout << "No fcalls running time -> " <<1000.0 * (end - start)/CLOCKS_PER_SEC << std::endl;
  std::cout << "Ran " << j << "times" << std::endl;
}