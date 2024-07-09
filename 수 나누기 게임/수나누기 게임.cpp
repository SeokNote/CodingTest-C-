#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Nums;
bool Arr[1000001] = { false };
int Score[1000001] = { 0 };

void Check(int _Number)
{
	int Number = Nums[_Number];
	for (int i = Number*2; i < 1000001; i+=Number)
	{
		if (Arr[i] == true)
		{
			Score[Number]++;
			Score[i]--;
		}
	}

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	std::cin >> N;
	Nums.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Nums[i];
		Arr[Nums[i]] = true;
	}

	for (int i = 0; i < N; i++)
	{
		Check(i);
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << Score[Nums[i]] << " ";
	}
	return 0;
}