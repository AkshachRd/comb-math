#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "lw1_6.h"

void GenerateAllSubsetsOfASet(std::vector<int>& b, int n)
{
    while (b[n] != 1)
    {
        //std::reverse_copy(b.begin(), b.end() - 1, std::ostream_iterator<int>(std::cout, " "));
        //std::cout << std::endl;
        int i = 0;
        while (b[i] == 1)
        {
            b[i] = 0;
            ++i;
        }
        b[i] = 1;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> b;
    b.resize(n + 1, 0);
    
    auto start = std::chrono::steady_clock::now();
    
    GenerateAllSubsetsOfASet(b, n);
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}