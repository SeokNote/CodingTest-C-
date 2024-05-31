#include <iostream>
#include <vector>
#include <queue>
//첫번째 풀이
//
////첫 번째 갇힌 공기를 찾는다. 
////공기로 bfs돌고 2로 바꾸고 0은 갇힌 공기 
////두 변이 접촉한 치즈를 찾아 공기(2)로 바꾼다
////위에 반복
//std::vector<std::vector<int>> Grid;
//std::vector<std::vector<int>> CopyGrid;
//
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int N, M;
//
//void ChangeAir(int _y, int _x)
//{
//	Grid[_y][_x] = 0;
//	std::queue<std::pair<int, int>> q;
//	q.push({ _y, _x });
//	while (!q.empty())
//	{
//		std::pair<int, int> curpos = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int CheckX = curpos.second + dx[i];
//			int CheckY = curpos.first + dy[i];
//			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
//			{
//				continue;
//			}
//
//			if (Grid[CheckY][CheckX] == 1)
//			{
//				continue;
//			}
//
//			if (Grid[CheckY][CheckX] == 2)
//			{
//				continue;
//			}
//
//			Grid[CheckY][CheckX] = 2;
//			q.push({ CheckY, CheckX });
//
//		}
//	}
//
//}
//
//void ChangeCheese()
//{
//	for (int y = 0; y < N; y++)
//	{
//		for (int x = 0; x < M; x++)
//		{
//			if (CopyGrid[y][x] == 1)
//			{
//				int cnt = 0;
//				for (int i = 0; i < 4; i++)
//				{
//					int CheckX = x + dx[i];
//					int CheckY = y + dy[i];
//					if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
//					{
//						continue;
//					}
//					if (CopyGrid[CheckY][CheckX] == 1)
//					{
//						continue;
//					}
//					if (CopyGrid[CheckY][CheckX] == 2)
//					{
//						cnt++;
//					}
//				}
//				if (cnt >= 2)
//				{
//					Grid[y][x] = 2;
//				}
//			}
//
//		}
//	}
//}
//
//void Init()
//{
//	for (int y = 0; y < N; y++)
//	{
//		for (int x = 0; x < M; x++)
//		{
//			if (Grid[y][x] == 2)
//			{
//				Grid[y][x] = 0;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int answer = 0;
//	std::cin >> N >> M;
//	Grid.resize(N);
//	for (int y = 0; y < N; y++)
//	{
//		Grid[y].resize(M);
//		for (int x = 0; x < M; x++)
//		{
//			std::cin >> Grid[y][x];
//		}
//	}
//
//	for (int y = 0; y < N; y++)
//	{
//		for (int x = 0; x < M; x++)
//		{
//			if (Grid[y][x] == 1)
//			{
//				ChangeAir(0, 0);
//				CopyGrid = Grid;
//				ChangeCheese();
//				Init();
//				answer++;
//			}
//		}
//	}
//	std::cout << answer;
//	return 0;
//}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ두 번째 풀이ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
#include <iostream>
#include <vector>
#include <queue>
//첫 번째 갇힌 공기를 찾는다. 
//공기로 bfs돌고 2로 바꾸고 0은 갇힌 공기 
//두 변이 접촉한 치즈를 찾아 공기(2)로 바꾼다
//위에 반복
std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> Cheeses;
std::vector<std::vector<int>> CopyGrid;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

void ChangeAir(int _y, int _x)
{
	Grid[_y][_x] = 0;
	std::queue<std::pair<int, int>> q;
	q.push({ _y, _x });
	while (!q.empty())
	{
		std::pair<int, int> curpos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int CheckX = curpos.second + dx[i];
			int CheckY = curpos.first + dy[i];
			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 1)
			{
				Cheeses[CheckY][CheckX]++;
				continue;
			}

			if (Grid[CheckY][CheckX] == 2)
			{
				continue;
			}

			Grid[CheckY][CheckX] = 2;
			q.push({ CheckY, CheckX });

		}
	}

}

void ChangeCheese()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (CopyGrid[y][x] == 1)
			{
				int cnt = 0;
				for (int i = 0; i < 4; i++)
				{
					int CheckX = x + dx[i];
					int CheckY = y + dy[i];
					if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
					{
						continue;
					}
					if (CopyGrid[CheckY][CheckX] == 1)
					{
						continue;
					}
					if (CopyGrid[CheckY][CheckX] == 2)
					{
						cnt++;
					}
				}
				if (cnt >= 2)
				{
					Grid[y][x] = 2;
				}
			}

		}
	}
}

void EraseCheese()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (Cheeses[y][x] >= 2)
			{
				Grid[y][x] = 2;
			}
		}
	}
}

void Init()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			Cheeses[y][x] = 0;
			if (Grid[y][x] == 2)
			{
				Grid[y][x] = 0;
			}
		}
	}
}

int main()
{
	int answer = 0;
	std::cin >> N >> M;
	Grid.resize(N);
	Cheeses.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		Cheeses[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			Cheeses[y][x] = 0;
			std::cin >> Grid[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (Grid[y][x] == 1)
			{
				ChangeAir(0, 0);
				//CopyGrid = Grid;
				EraseCheese();
				Init();
				//ChangeCheese();
				//Init();
				answer++;
			}
		}
	}
	std::cout << answer;
	return 0;
}
