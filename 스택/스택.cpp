#include <iostream>
#include <vector>
struct stack 
{
	//1~10000까지의 범위
	int arr[10001] = { 0 };
	int index = -1;

	void push(int num) 
	{
		arr[++index] = num;
	}
	bool empty() 
	{
		if (index < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int pop() 
	{
		if (empty() == true) 
		{
			return -1;
		}
		return arr[index--];
	}
	int size() 
	{
		int size = index + 1;
		return size;
	}
	int top() 
	{
		if (empty()== true) 
		{
			return -1;
		}
		return arr[index];
	}
};
int main()
{
	std::vector<int> answer;
	stack st;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::string str = "";
		std::cin >> str;
		if (str == "push")
		{
			int num = 0;
			std::cin >> num;
			st.push(num);
		}
		else if (str == "top")
		{
			answer.push_back(st.top());
		}
		else if (str == "size")
		{
			answer.push_back(st.size());
		}
		else if (str == "pop")
		{
			answer.push_back(st.pop());
		}
		else if (str == "empty")
		{
			if (st.empty() == true)
			{
				answer.push_back(1);
			}
			else
			{
				answer.push_back(0);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << "\n";
	}
	return 0;
}