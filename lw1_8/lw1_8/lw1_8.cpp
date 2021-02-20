#include <iostream>
#include <optional>
#include <vector>
#include <utility>

struct Backpack
{
    int n;
    int T;
    int S;
    std::vector<std::pair<int, int>> things;
};

Backpack ReadInput()
{
    Backpack b;
    std::cin >> b.n >> b.T >> b.S;
    b.things.resize(b.n);
    for (int i = 0; i < b.n; ++i)
    {
        int first, second;
        std::cin >> first >> second;
        b.things[i] = std::make_pair(first, second);
    }
    return b;
}

int main()
{
    Backpack j;
    j = ReadInput();
    std::cout << j.n << "#" << j.T << "#" << j.S;
    return 0;
}