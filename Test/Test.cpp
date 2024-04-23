#include <iostream>
#include <vector>
#include <set>
int main()
{
	int N,M;
	std::cin >> N>>M;
	std::vector<int> answer;
	std::vector<std::string> keword;
	std::set<std::string> Newkeword;
	std::vector<std::string> searchkeword1;
	keword.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> keword[i];
	}
	for (int i = 0; i < M; i++)
	{
		std::string str = "";
		std::cin >> str;
		while (str.find(',') != std::string::npos)
		{
			size_t slice = str.find(',');
			Newkeword.insert(str.substr(0, slice));
			str.erase(str.begin(), str.begin() + slice);
			str.erase(str.begin());
		}
		Newkeword.insert(str);
		answer.push_back(N - Newkeword.size());
	}
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << "\n";
	}
	return 0;
}
