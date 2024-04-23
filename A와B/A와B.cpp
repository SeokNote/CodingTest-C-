#include <iostream>
#include <algorithm>
#include <vector>

std::string SubA(std::string _str)
{
	_str.pop_back();
	return _str;
}

std::string ReverseSubB(std::string _str)
{
	_str.pop_back();
	std::reverse(_str.begin(), _str.end());
	return _str;
}

int main()
{
	std::string S = "";
	std::string T = "";
	std::cin >> S >> T;

	while (1)
	{
		if (T[T.size() - 1] == 'A')
		{
			T = SubA(T);
		}
		else
		{
			T = ReverseSubB(T);
		}
		if (T == S)
		{
			std::cout << "1";
			return 0;
		}
		if (T.size() == 0)
		{
			std::cout << "0";
			return 0;
			break;
		}
	}
	return 0;
}