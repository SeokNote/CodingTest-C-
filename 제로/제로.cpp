#include <iostream>
#include <stack>

int main()
{
	int t;
	std::stack<int> st;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int num = 0;
		std::cin >> num;
		if (num != 0)
		{
			st.push(num);
		}
		else
		{
			if (!st.empty())
			{
				st.pop();
			}
		}
	}
	int answer = 0;
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}
	std::cout << answer;
	return 0;
}