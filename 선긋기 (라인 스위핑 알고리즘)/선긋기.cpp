#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int, int>> arr;
int INF = 1e9 + 1;

int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	arr.resize(1000000);

	for (int i = 0; i < N; i++) 
	{
		int start, end;
		std::cin >> start >> end;
		arr[i].first = start;
		arr[i].second = end;//³¡
	}

	std::sort(arr.begin(), arr.begin() + N); 

	int temp = 0;
	int result = 0;
	int l = -INF;
	int r = -INF;

	for (int i = 0; i < N; i++) {
		if (arr[i].first < r) 
		{
			r = std::max(r, arr[i].second);
		}
		else 
		{
			result += r - l;
			l = arr[i].first;
			r = arr[i].second;
		}
	}
	result += r - l;
	std::cout << result;
	return 0;
}