#include <string>
#include <vector>
#include <iostream>
bool IsVisit[10001] = { false };

//n���� ���� �� �ִ� �����ڸ� ã���ִ� �Լ�.
int selfnuber(int num)
{
	int result = 0;
	std::string str = std::to_string(num);
	for (int i = 0; i < str.size(); i++)
	{
		result += str[i] - '0';
	}
	result += num;
	return result;
}

int main()
{
	for (int i = 0; i < 10000; i++)
	{
		IsVisit[selfnuber(i)] = true;
	}
	for (int i = 0; i < 10000; i++)
	{
		if (IsVisit[i] == false)
		{
			std::cout << i << "\n";
		}
	}
	return 0;
}