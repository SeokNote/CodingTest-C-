#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
bool isPrime2(int n) 
{
	for (int i = 2; i <= sqrt(n); i++) 
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int solution(string numbers)
{
	int answer = 0;
	std::vector<int> number;
	number.reserve(numbers.size());
	for (int i = 0; i < numbers.size(); i++)
	{
		number.push_back(numbers[i]-'0');
	}
	std::sort(number.begin(), number.end());
	std::set<int> nums;

		std::vector<bool> temp(10);
		fill(temp.begin(), temp.end(), false);
		for (int j = 0; j < 1; j++)
		{
			temp[j] =true;
		}
		do
		{
			//std::string str = "";
			for (int i = 0; i < number.size(); ++i)
			{
				if (temp[i] == true)
				{
					//std::cout << number[i];
				}
				//if (isPrime2(std::stoi(str)) == true)
				//{
				//	nums.insert(std::stoi(str));
				//}
			}
			
		} while (std::next_permutation(temp.begin(), temp.end()));

	answer = nums.size();
    return answer;
}
int main()
{
	solution("17");
	return 0;
}