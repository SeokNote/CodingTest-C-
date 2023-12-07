#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <sstream>
std::vector<int> Arr;
std::set<std::vector<int>> Answer;
std::vector<int> vec;
int main()
{
	//std::string a("1000:10:100:A");
	//int b, c, d;
	//char e;
	//for (int i = 0; i < 3; i++)
	//{
	//	a.replace(a.find(":"), 1, " ");
	//}
	//std::stringstream KK(a);

	//KK >> b;
	//KK >> c;
	//KK >> d;
	//KK >> e;

	int Num = 0;
	int R = 0;
	int Count = 0;
	std::cin >> Num >> R;
	Arr.reserve(Num);
	for (int i = 0; i < Num; i++)
	{
		int A = 0;
		std::cin >> A;
		Arr.push_back(A);
	}
	std::vector<int> temp(Num, 0);
	for (int i = 0; i < R; i++)
	{
		temp[i] = 1;
	}
	std::sort(Arr.begin(), Arr.end());
	do
	{
		for (int i = 0; i < Arr.size(); ++i)
		{
			if (temp[i] == 1)
			{
				vec.push_back(Arr[i]);
			}
		}
		Answer.insert(vec);
		vec.clear();
	} while (std::next_permutation(Arr.begin(), Arr.end()));
	for (auto i : Answer)
	{
		std::copy(i.begin(), i.end(), std::ostream_iterator<int>(std::cout, " "));

		//for (auto& j : i)
		//{
		//	std::cout << j << " ";
		//}
		std::cout << "\n";
	}
}