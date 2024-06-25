#include <iostream>
#include <string>

int main()
{
	int K;
	std::cin >> K;//a : 10진수 , b : 2진수 
	int res = 0;
	//10진 to 2진  
	if (K <= 2)
	{
		if (K == 1)
		{
			std::cout << "4";
			return 0;
		}
		else
		{
			std::cout << "7";
			return 0;
		}
	}

	for (int i = 1; K >= 1; i *= 10) 
	{
		res = (K % 2) * i + res;
		K /= 2;
	}

	std::string str = std::to_string(res);
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == '1')
		{
			str[i] = '4';
		}
		else
		{
			str[i] = '7';
		}
	}
	
	
	std::cout << str;
	return 0;
}