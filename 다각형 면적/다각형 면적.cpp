#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
std::vector<std::pair<int, int>> vec;
long double solution(int i)
{
	long double x1 = vec[0].first;
	long double y1 = vec[0].second;
	long double x2 = vec[i].first;
	long double y2 = vec[i].second;
	long double x3 = vec[i + 1].first;
	long double y3 = vec[i + 1].second;
	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main()
{
	int N;
	std::cin >> N;
	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int x = 0;
		int y = 0;
		std::cin >> x >> y;
		vec.push_back(std::make_pair(x, y));
	}

	long double answer = 0;
	for (int i = 1; i < N - 1; i++)
	{
		answer += solution(i);
	}
	std::fixed;
	std::cout.precision(1);
	std::cout << abs(answer) << std::endl;
	return 0;
}
