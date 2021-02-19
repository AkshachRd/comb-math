#include <array>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <iostream>
#define N 10

int main()
{
	std::array<int, N + 2> now;
	std::array<int, N + 1> rev;
	std::array<int, N + 1> shift;

	int m = N + 1;

	for (int i = 1; i <= N; i++)
	{
		now[i] = i;
		rev[i] = i;
		shift[i] = -1;
	}

	now[0] = N + 1;
	now[N + 1] = N + 1;
	shift[1] = 0;

	auto start = std::chrono::steady_clock::now();

	while (m != 1)
	{
		m = N;
		while (now[rev[m] + shift[m]] > m)
		{
			shift[m] = -shift[m];
			m--;
		}

		std::iter_swap(now.begin() + rev[m], now.begin() + rev[m] + shift[m]);
		std::iter_swap(rev.begin() + now[rev[m]], rev.begin() + m);
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return 0;
}