#include <iostream>
#include <vector>

int grid[9][9];
int N;
std::vector<std::pair<int, int> > v;

bool isend = false;

bool rowcheck(int row, int checknum) //가로세로
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[row][i] == checknum)
		{
			return false;
		}

	}
	return true;
}

bool colcheck(int col, int checknum)//위아래
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[i][col] == checknum)
		{
			return false;
		}
	}
	return true;
}
bool check(int x, int y, int value)
{

	if (colcheck(y, value) == false)
	{
		return false;
	}
	if (rowcheck(x, value) == false)
	{
		return false;
	}
	//3x3 칸 내에 value 이미 존재하는지 탐색
	int part_x = x / 3;
	int part_y = y / 3;
	part_x *= 3;
	part_y *= 3;
	for (int i = part_x; i < part_x + 3; i++)
	{
		for (int j = part_y; j < part_y + 3; j++)
		{
			if (grid[i][j] == value)
			{
				return false;
			}
		}
	}
	return true;
}

void DFS(int cur)
{
	if (isend == true)
	{
		return;
	}
	if (cur == N)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				std::cout << grid[i][j];
			}
			std::cout << '\n';
		}
		isend = true;
	}
	else
	{
		int nx = v[cur].first;
		int ny = v[cur].second;
		for (int i = 1; i <= 9; i++)
		{
			if (check(nx, ny, i))
			{
				grid[nx][ny] = i;
				DFS(cur + 1);
				//위에 DFS가 정답이 아닐 수도 있으니 초기화하고 돌아줘야한다.
				grid[nx][ny] = 0;
			}
		}
	}
}


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		std::string str = "";
		std::cin >> str;
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = str[j] - '0';
			if (grid[i][j] == 0)
			{
				v.push_back({ i,j });
			}
		}
	}
	N = v.size();
	DFS(0);
	
	return 0;
}