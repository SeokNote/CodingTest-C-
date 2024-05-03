#include <iostream>
#include <algorithm>
#include <vector>
bool checkstr(const std::string& str, int _left, int _right)
{
	bool Avalue = str[_left + 1] == str[_right];
	bool Bvalue = str[_left] == str[_right - 1];
	if (Avalue && Bvalue)
	{
		return checkstr(str, _left + 1, _right - 1);
	}
	return Avalue;
}
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> answer;
	answer.reserve(N);
	for (int i = 0; i < N; i++)
	{
		std::string str = "";
		std::cin >> str;
		int size = str.size();
		int right = size - 1;
		int cnt = 0;
		for (int left = 0; left <= size / 2; left++)
		{

			while (str[left] != str[right] && right >= size / 2)
			{
				cnt++;
				bool IsValue = checkstr(str, left, right);
				if (IsValue == true)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
			right--;
		}
		if (cnt > 1)
		{
			answer.push_back(2);
		}
		else if (cnt == 1)
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}

	}
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << "\n";
	}
	return 0;
}

