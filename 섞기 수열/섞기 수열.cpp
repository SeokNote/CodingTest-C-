#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> shake;
std::vector<int> nums;
std::vector<long long> answer;
std::vector<int> temp;
int cnt = 0;
int complet = 0;
long long gcd(long long a, long long b) // a > b
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

void cardshuffle()
{
	temp = nums;
	cnt++;
	for (int i = 1; i <= N; i++)
	{
		nums[i] = temp[shake[i]];
		if (nums[i] == i && answer[i] == -1)
		{
			answer[i] = cnt;
			complet++;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	shake.resize(N + 1);
	answer.resize(N + 1, -1);
	nums.resize(N + 1);
	temp.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int num = 0;
		std::cin >> num;
		shake[i] = num;
	}

	for (int i = 1; i <= N; i++)
	{
		nums[i] = i;
		temp[i] = i;
	}

	while (complet != N)
	{
		cardshuffle();
	}

	long long lcmnum = answer[1];

	for (int i = 2; i < answer.size(); i++)
	{
		lcmnum = lcm(lcmnum, answer[i]);
	}

	std::cout << lcmnum;

	return 0;

}