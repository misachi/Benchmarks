#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

using std_clk = std::chrono::steady_clock;
using std_duration = std::chrono::duration<double>;
using std::chrono::duration_cast;

__attribute__((noinline)) static void func_ptr(std::vector<int*> v) {
    size_t res = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        res += *v[i];

    }
}

template<typename T>
__attribute__((noinline)) static void func_value(std::vector<T> v) {
    size_t res = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        res += v[i];
    }
}

int main() {
    std::random_device rdev;
    std::mt19937_64 engine(rdev());
    std::uniform_int_distribution<> dist(1000, 10000);

    int size {dist(engine)};
    std::cout << "Size: " << size << "\n";
    std::cout << "\n";
    std::vector<int*> v_ptr;
    for (size_t i=0; i < static_cast<size_t>(size); i++)
    {
        v_ptr.push_back(new int{size});
    }

    std::vector<std::reference_wrapper<int>> v_ref;
    for (size_t i=0; i < static_cast<size_t>(size); i++)
    {
        v_ref.push_back(size);
    }

    std::vector<int> v_val;
    for (size_t i=0; i < static_cast<size_t>(size); i++)
    {
        v_val.push_back(size);
    }

    auto start = std_clk::now();
    func_ptr(v_ptr);
    auto end = std_clk::now();

    std_duration duration = end - start;
    std::cout << "Pointer dereference....\n";
    std::cout << "Time taken: " << duration.count() << " seconds\n";

    std::cout << "\n";

    start = std_clk::now();
    func_value(v_ref);
    end = std_clk::now();

    duration = end - start;
    std::cout << "Element Reference types....\n";
    std::cout << "Time taken: " << duration.count() << " seconds\n";

    std::cout << "\n";

    start = std_clk::now();
    func_value(v_val);
    end = std_clk::now();

    duration = end - start;
    std::cout << "Element value types....\n";
    std::cout << "Time taken: " << duration.count() << " seconds\n";

    for (size_t i = 0; i < v_ptr.size(); i++)
    {
        delete v_ptr[i];
    }
    
}