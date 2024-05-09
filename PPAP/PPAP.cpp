#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
int main()
{
	std::string str = "";
	std::cin >> str;
	std::stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		if (st.size() < 3)
		{
			st.push(str[i]);
			continue;
		}
		if (str[i] == 'P' && str[i - 1] == 'A')
		{
			st.pop();
			char prevstr = st.top();
			st.pop();
			char prevstr1 = st.top();
			st.pop();
			if (prevstr == prevstr1 && prevstr == 'P')
			{
				st.push(str[i]);
				continue;
			}
			else
			{
				st.push('A');
				st.push('P');
			}
		}
		st.push(str[i]);
	}
	if (st.top() == 'P' && st.size() == 1)
	{
		std::cout << "PPAP";
	}
	else
	{
		std::cout << "NP";
	}
	return 0;
}

