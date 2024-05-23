#include<iostream>
#include <vector>
#include <algorithm>

int Checkerboard[20][20] = { 0 };
int dx[8] = { -1,0,1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };
std::vector<std::pair<int, int>> answer;

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

//오목이 되는지 체크
bool WinCheck(int _y, int _x, int _num, int _dir)
{
	int cnt = 0;
	int prevy = _y - dy[_dir];
	int prevx = _x - dx[_dir];
	//검사하고자 하는 방향 반대를 체크하며 6목 방지
	if (Checkerboard[prevy][prevx] != _num || prevy < 0 || prevx < 0 || prevy>20 || prevx>20)
	{
		for (int i = 1; i < 5; i++)
		{
			int nexty = _y + dy[_dir] * i;
			int nextx = _x + dx[_dir] * i;
			if (nexty < 0 || nextx < 0 || nexty>20 || nextx>20)
			{
				return false;
			}
			if (Checkerboard[nexty][nextx] == _num)
			{
				cnt++;
			}
			if (cnt == 4)
			{
				//다음칸 체크하며 6목 방지
				int nnextx = nextx + dx[_dir];
				int nnexty = nexty + dy[_dir];
				if (nexty < 0 || nextx < 0 || nexty>20 || nextx>20)
				{
					return false;
				}
				if (Checkerboard[nnexty][nnextx] != _num)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int Winnum = 0;
	for (int y = 0; y < 19; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			std::cin >> Checkerboard[y][x];
		}
	}
	for (int y = 0; y < 19; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			if (Checkerboard[y][x] == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					if (WinCheck(y, x, 1, i))
					{
						Winnum = 1;
						answer.push_back(std::make_pair(y + 1, x + 1));
					}
					else
					{
						continue;
					}
				}
			}
			else if (Checkerboard[y][x] == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					if (WinCheck(y, x, 2, i))
					{
						Winnum = 2;
						answer.push_back(std::make_pair(y + 1, x + 1));
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				continue;
			}
		}
	}
	int min = INT32_MAX;
	int minx = 0;
	int miny = 0;

	if (answer.size() > 0)
	{
		// 제일 왼쪽 위의 값이 정답
		std::sort(answer.begin(), answer.end(), cmp);
		std::cout << Winnum << "\n";
		std::cout << answer[0].first << " " << answer[0].second;
	}
	else
	{
		std::cout << 0;
	}
	return 0;
}