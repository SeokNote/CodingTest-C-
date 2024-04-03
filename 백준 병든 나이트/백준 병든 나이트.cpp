#include <iostream>
int N, M;
int answer = 0;
int dx[4] = {1,2,2,1};
int dy[4] = {2,1,-1,-2};
int MaxX, MaxY;
void DFS(int _StartPosX, int _StartPosY)
{
	answer++;
	for (size_t i = 0; i < 4; i++)
	{
		int CheckX = _StartPosX + dx[i];
		int CheckY = _StartPosY + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= MaxX || CheckY >= MaxY)
		{
			continue;
		}
		DFS(CheckX, CheckY);
	}
}

int main()
{

    std::cin >> N >> M;
	MaxX = M;
	MaxY = N;
	DFS(0, M);
	std::cout << answer;
    return 0;
}