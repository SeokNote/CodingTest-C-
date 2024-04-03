#include <iostream>
#include <map>

int main()
{
	int N = 0;
	std::string str = "";
	std::cin >> N >> str;
	int right = 0;
	int max = 0;
	std::map<char, int> checkstr;
	for (int left = 0; left < str.size(); left++)
	{

		while (checkstr.size() <= N && right < str.size())
		{
			checkstr[str[right]] += 1;
			right++;
		}

		if (checkstr.size() > N)
		{
			max = std::max(max, right - left -1);
		}
		else
		{
			max = std::max(max, right - left);
		}

		checkstr[str[left]] -= 1;
		if (checkstr[str[left]] == 0)
		{
			checkstr.erase(str[left]);
		}
	}
	std::cout << max;

	return 0;
}