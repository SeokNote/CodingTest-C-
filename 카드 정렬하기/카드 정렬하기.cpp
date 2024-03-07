#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
int main()
{
	int N;
	int answer = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		pq.push(num);
	}
	while (pq.size() != 1)
	{
		int sum = 0;
		sum += pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		answer += sum;
	}

	std::cout << answer;
	return 0;
}
