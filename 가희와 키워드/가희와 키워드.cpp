#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	std::unordered_set<std::string> keyword;
	std::vector<int> answer;
	//std::unordered_map<> keword;
	std::set<std::string> Newkeword;
	std::vector<std::string> searchkeword1;
	for (int i = 0; i < N; i++)
	{
		std::string str = "";
		std::cin >> str;
		keyword.insert(str);
	}
	for (int i = 0; i < M; i++)
	{
		std::string str = "";
		std::cin >> str;
		std::stringstream ss(str);
		
		std::string temp;
		while (std::getline(ss,temp,','))
		{
			keyword.erase(temp);
		}
		answer.push_back(keyword.size());
	}
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << "\n";
	}
	return 0;
}
