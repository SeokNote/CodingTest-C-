#include <iostream>
#include <queue>


int main()
{

	int n, k;
	std::cin >> n >> k;
	std::cout << "<";
	std::queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (q.size()!=1) 
	{
		for (int i = 0; i < k-1; i++) 
		{
			int tmp = q.front();
			q.pop(); 
			q.push(tmp);
		}
		std::cout << q.front() << ", ";
		q.pop();
	}
	std::cout << q.front() << ">\n";
}