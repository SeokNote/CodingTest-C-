#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main()
{
	int n;
	std::string str = "";
	std::stack<double> st;
	std::cin >> n;
	std::cin >> str;
	std::vector<int> vec;
	vec.resize(str.size());
	for (int i = 0; i < n; i++)
	{
		
		std::cin >> vec[i];
		
	}

	for (int i = 0; i < str.size(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			st.push(vec[str[i] - 'A']);
		}
		else
		{
			if (!st.empty())
			{
				double num1 = st.top();
				st.pop();
				double num2 = st.top();
				st.pop();
				if (str[i] == '-')
				{
					st.push(num2 - num1);
				}
				else if (str[i] == '/')
				{
					st.push(num2 / num1);
				}
				else if (str[i] == '*')
				{
					st.push(num2 * num1);
				}
				else if(str[i] == '+')
				{
					st.push(num2 + num1);
				}
			}
			
			}
		
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << st.top();
	return 0;
}
