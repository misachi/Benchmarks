#include <chrono>
#include <ctime>
#include <iostream>
#include <random>

using std_clk = std::chrono::steady_clock;
using std_duration = std::chrono::duration<double>;
using std::chrono::duration_cast;

__attribute__((noinline)) int foo(int n) {
  // Some algorithm
  return n * 2 / 10;
}

int main() {
  std::random_device r_dev;
  std::mt19937_64 engine(r_dev());
  std::uniform_int_distribution<> udist(10000, 1000000);

  std_clk::time_point start, end;
  size_t size = udist(engine);
  long j;
  std::cout << "Start loop with function calls" << std::endl;
  start = std_clk::now();
  for (size_t i = 0; i < size; ++i)
    j = foo(i);
  std::cout << "Ran " << j << "times" << std::endl; 
  end = std_clk::now();

  std_duration time_span = duration_cast<std_duration>(end - start);
  std::cout << "Fcalls running time -> " << time_span.count() << " seconds"
            << std::endl;

  std::cout << std::endl;

  std::cout << "Start loop no function calls" << std::endl;

  start = std_clk::now();
  j = 0;
  for (size_t i = 0; i < size; ++i) {
    j = i * 2 / 10;
  }
  end = std_clk::now();

  time_span = duration_cast<std_duration>(end - start);
  std::cout << "No fcalls running time -> " << time_span.count() << " seconds" << std::endl;
  std::cout << "Ran " << j << "times" << std::endl;
}