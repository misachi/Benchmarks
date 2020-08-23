#include <iostream>
#include <random>

int main() {
    std::random_device dev;
    std::mt19937_64 engine(dev());
    std::uniform_int_distribution<> dist(10000, 1000000);

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << dist(engine) << " ";
    }
    std::cout << "\n";
    
}