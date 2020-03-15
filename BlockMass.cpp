#include <iostream>
#include <vector>
#include <limits>


int main()
{
    uint64_t n = 0;
    uint64_t r = 0;
    uint64_t w = 0, h = 0, d = 0;
    uint64_t mass = 0;

    std::cin >> n >> r;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> w >> h >> d;
        mass += w * h * d * r;
    }

    std::cout << mass << std::endl;

    return 0;
}
