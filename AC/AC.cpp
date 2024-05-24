#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <deque>
int main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::deque<int> dq;
		std::string p = "";
		bool ErrorValue = false;
		int n;
		std::string str = "";
		std::cin >> p >> n >> str;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] < '0' || '9' < str[i])
			{
				str[i] = ' ';
			}
		}

		std::stringstream ss(str);
		for (size_t i = 0; i < n; i++)
		{
			int num;
			ss >> num;
			dq.push_back(num);
		}

		int ReverseValue = 1;
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] == 'R')
			{
				ReverseValue *= -1;
			}
			else if (p[j] == 'D')
			{
				if (ErrorValue == false)
				{
					if (dq.size() > 0)
					{
						if (ReverseValue == -1)
						{
							dq.pop_back();
						}
						else
						{
							dq.pop_front();
						}
					}
					else
					{
						std::cout << "error" << "\n";
						ErrorValue = true;
						break;
					}
				}

			}
		}

		if (ErrorValue == false)
		{
			std::cout << "[";
			if (ReverseValue == -1 && !dq.empty())
			{
				for (int j = dq.size() - 1; j >= 0; j--)
				{
					std::cout << dq[j];
					if (j != 0)
					{
						std::cout << ",";
					}
				}
			}
			else if (!dq.empty() && ReverseValue == 1)
			{
				for (int j = 0; j < dq.size(); j++)
				{
					std::cout << dq[j];
					if (j != dq.size() - 1)
					{
						std::cout << ",";
					}
				}
			}
			std::cout << "]" << "\n";
		}

	}

	return 0;
}