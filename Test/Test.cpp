#include <iostream>
#include <algorithm>
#include <vector>
std::vector<int> numtable(100001, 0);
int main()
{
	int N, M;
	std::cin >> N >> M;
	int right = 0;
	std::vector<int> nums;
	int answer = -1;
	nums.resize(N+1);
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		nums[i]=num;
	}
	for (int left = 0; left < nums.size(); left++)
	{

		while (numtable[nums[right]] < M && right < N)
		{
			numtable[nums[right]] += 1;
			right++;
		}
		answer = std::max(answer, right - left);
		if (right == N)
		{
			break;
		}
		numtable[nums[left]] -= 1;
	}
	std::cout << answer;

	return 0;
}

