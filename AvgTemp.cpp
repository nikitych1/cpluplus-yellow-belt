#include <iostream>
#include <vector>

int main()
{
    size_t n = 0;
    int temp = 0;
    int64_t avg = 0;
    std::cin >> n;
    std::vector<int> data, indxs;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        data.push_back(temp);
        avg += temp;
    }

    avg /= static_cast<int>(data.size());

    for (size_t i = 0; i + 1 < data.size() + 1; ++i)
        if (data.at(i) > avg)
            indxs.push_back(i);

    std::cout << indxs.size() << std::endl;

    for (auto i : indxs)
        std::cout << i << " ";

    return 0;
}
