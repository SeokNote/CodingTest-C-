#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

	while (true)
	{
		std::vector<int> number;
		std::vector<std::pair<int, int>> answer;
		int x, n;
		std::cin >> x >> n;
		if (std::cin.eof())
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			int num = 0;
			std::cin >> num;
			number.push_back(num);
		}

		int length = x * 10000000;
		bool IsValue = false;
		int left=0;
		int right = n - 1;
		int checknum = 0;

		std::sort(number.begin(), number.end());

		while (left < right)
		{
			checknum = number[left] + number[right];

			if (checknum == length)
			{
				std::cout << "yes " << number[left] << " " << number[right] << '\n';
				break;
			}
			else if (checknum < length)
			{
				left++;
			}
			else if (checknum > length)
			{
				right--;
			}
		}
		if (checknum != length)
		{

			std::cout << "danger" << "\n";
		}
	}
	return 0;
}