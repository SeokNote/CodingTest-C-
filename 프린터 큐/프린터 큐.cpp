#include <iostream>
#include <queue>

//우선순위가 _index번째
int PrintQueue(int _num, int _index, std::vector<int>& vec)
{
	int answer = 0;
	std::queue<std::pair<int, int>> q;
	std::priority_queue<int> pq;
	for (int i = 0; i < vec.size(); i++)
	{
		q.push(std::make_pair(vec[i], i));
		pq.push(vec[i]);
	}

	while (!pq.empty())
	{
		if (pq.top() == q.front().first)
		{
			answer++;
			if (q.front().second == _index)
			{
				return answer;
			}
			pq.pop();
			q.pop();

		}
		else
		{
			std::pair<int, int> cur = q.front();
			q.pop();
			q.push(cur);
		}
	}

	return answer;
}

int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		int index = 0;
		std::cin >> num >> index;
		std::vector<int> numbers;
		numbers.resize(num);
		for (int i = 0; i < num; i++)
		{
			std::cin >> numbers[i];
		}
		std::cout << PrintQueue(num, index, numbers) << "\n";
	}
	return 0;
}