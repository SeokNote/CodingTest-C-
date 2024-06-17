#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;
int N, M;

//first y second x
std::vector<std::vector<std::pair<int, int>>> Dir;
int max = 0;
int BFS(int _y,int _x)
{
	int Wegiht = 0;
	IsVisit[_y][_x] = true;
	std::queue<std::pair<int, int>> q;
	q.push({ _y, _x });
	while (!q.empty())
	{
		std::pair<int, int> curpos = q.front();
		q.pop();
		for (int i = 0; i < Dir[Grid[curpos.first][curpos.second]].size(); i++)
		{
			int CheckX = curpos.second + Dir[Grid[curpos.first][curpos.second]][i].second;
			int CheckY = curpos.first + Dir[Grid[curpos.first][curpos.second]][i].first;
			if (CheckX < 0 || CheckY < 0 || CheckX >= N  || CheckY >= M )
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX] == true)
			{
				continue;
			}
			Wegiht++;
			IsVisit[CheckY][CheckX] = true;
			q.push({ CheckY, CheckX });

		}
	}
	return Wegiht;
}

int main()
{
	std::cin >> N >> M;
	Dir.resize(16);
	Dir[1].push_back(std::make_pair(-1, 0));
	Dir[1].push_back(std::make_pair(1, 0));
	Dir[1].push_back(std::make_pair(0, 1));

	Dir[2].push_back(std::make_pair(0, -1));
	Dir[2].push_back(std::make_pair(1, 0));
	Dir[2].push_back(std::make_pair(0, 1));

	Dir[3].push_back(std::make_pair(0, 1));
	Dir[3].push_back(std::make_pair(1, 0));

	Dir[4].push_back(std::make_pair(0, -1));
	Dir[4].push_back(std::make_pair(-1, 0));
	Dir[4].push_back(std::make_pair(1, 0));

	Dir[5].push_back(std::make_pair(-1, 0));
	Dir[5].push_back(std::make_pair(1, 0));
	
	Dir[6].push_back(std::make_pair(0, -1));
	Dir[6].push_back(std::make_pair(1, 0));

	Dir[7].push_back(std::make_pair(1, 0));

	Dir[8].push_back(std::make_pair(0, -1));
	Dir[8].push_back(std::make_pair(0, 1));
	Dir[8].push_back(std::make_pair(-1, 0));

	Dir[9].push_back(std::make_pair(-1, 0));
	Dir[9].push_back(std::make_pair(0, 1));

	Dir[10].push_back(std::make_pair(0, -1));
	Dir[10].push_back(std::make_pair(0, 1));


	Dir[11].push_back(std::make_pair(0, 1));

	Dir[12].push_back(std::make_pair(-1,0));
	Dir[12].push_back(std::make_pair(0, -1));

	Dir[13].push_back(std::make_pair(1, 0));

	Dir[14].push_back(std::make_pair(0, -1));

	Dir[15].push_back(std::make_pair(0, 0));

	Grid.resize(M);
	IsVisit.resize(M);
	for (int y = 0; y < M; y++)
	{
		Grid[y].resize(N);
		IsVisit[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
			IsVisit[y][x] = false;
		}
	}
	int Cnt = 0;
	for (int y = 0; y < M; y++)
	{

		for (int x = 0; x < N; x++)
		{
			if (IsVisit[y][x] == false)
			{
				Cnt++;
				max = std::max(max, BFS(y, x));
			}
		}
	}
	std::cout << Cnt<<"\n";
	std::cout << max;
	return 0;
}