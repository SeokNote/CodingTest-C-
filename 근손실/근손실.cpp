#include <iostream>
#include <algorithm>
#include <vector>

int cnt = 0;
int answer = 0;
int N, K;
int musle = 500;
std::vector<int> trainkit;
std::vector<bool> Isvisit;
void dfs(int _cnt) {
	if (_cnt == N-1)
	{
		answer++;
		return;
	}
	for (int i = 0; i < trainkit.size(); i++) 
	{
		if (Isvisit[i] == true)
		{
			continue;
		}
		Isvisit[i] = true;
		int curmusle = musle + trainkit[i] - K;
		if (curmusle>=500)
		{
			musle = musle + trainkit[i] - K;
			dfs(_cnt + 1);
			musle = musle - trainkit[i] + K;
		}
		Isvisit[i] = false;
		
	}
}

int main()
{
	std::cin >> N >> K;
	trainkit.resize(N);
	Isvisit.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> trainkit[i];
		Isvisit[i] = false;
	}
	dfs(0);
	std::cout << answer;
	return 0;
}

