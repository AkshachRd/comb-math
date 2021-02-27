#include <iostream>
#include <optional>
#include <algorithm>
#include <vector>

struct Backpack
{
    int n;
    int t;
    int s;
    std::vector<int> w;
    std::vector<int> c;
};

Backpack ReadInput()
{
    Backpack b;
    std::cin >> b.n >> b.t >> b.s;
    b.w.resize(b.n);
    b.c.resize(b.n);
    for (int i = 0; i < b.n; ++i)
    {
        int first, second;
        std::cin >> first >> second;
        b.w[i] = first;
        b.c[i] = second;
    }
    return b;
}

void GenerateAllSubsetsOfASet(std::vector<int>& vec, int n)
{
    while (vec[n] != 1)
    {
        //std::reverse_copy(vec.begin(), vec.end() - 1, std::ostream_iterator<int>(std::cout, " "));
        int i = 0;
        while (vec[i] == 1)
        {
            vec[i] = 0;
            ++i;
        }
        vec[i] = 1;
    }
}

int main()
{
    Backpack b = ReadInput();

    std::vector<int> vec;
    vec.resize(b.n + 1, 0);
    int sumW = 0, sumC = 0;
    while (vec[b.n] != 1)
    {
        sumW = 0;
        sumC = 0;
        for (int i = 0; i < b.n; ++i)
        {
            if (vec[i] == 1)
            {
                sumW += b.w[i];
                sumC += b.c[i];
            }
        }
        if ((sumW > 0 && sumW <= b.t) && (sumC > 0 && sumC >= b.s))
        {
            break;
        }
        int i = 0;
        while (vec[i] == 1)
        {
            vec[i] = 0;
            ++i;
        }
        vec[i] = 1;
    }

    std::cout << sumW << std::endl;
    for (int i = 0; i < b.n; ++i)
    {
        std::cout << vec[i];
    }

    return 0;
}