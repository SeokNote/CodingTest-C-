#include <iostream>

int DP[1000001] = {};
//x는 목적 ,y는 출발,n은 뺴는값.
int solution(int x, int y, int n)
{
	int answer = 0;
	for (int i = 0; i < 1000001; i++)
	{
		DP[i] = 999999;
	}
	DP[y] = 0;
	for (int i = y; i >= x; i--)
	{
		if (DP[i] != 999999)
		{
			if (i % 3 == 0)
			{
				DP[i / 3] = std::min(DP[i] + 1, DP[i / 3]);
			}
			if (i % 2 == 0)
			{
				DP[i / 2] = std::min(DP[i] + 1, DP[i / 2]);
			}
			if (i - n > 0)
			{
				DP[i - n] = std::min(DP[i] + 1, DP[i - n]);
			}
		}
	}
	if (DP[x] == 999999)
	{
		DP[x] = -1;
	}
	answer = DP[x];
	return answer;
}
/*
* 
#include <iostream>
#include <queue>
bool visited[99999999]; 
int x, y,n;

int bfs(int _startindex,int _endindex ,int _n)
{
    std::queue<std::pair<int, int>> q;
    q.push({ _startindex,0 }); 
    visited[_startindex] = 0;

    while (!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        if (pos < 0 || pos > 3000001)
        {
            continue;
        } 
        if (pos == _endindex)
        {
            return time;
        }
        if (visited[pos * 2] == false) 
        {
            visited[pos * 2] = true;
            q.push({ pos * 2, time + 1 }); 
        }
        if (visited[pos * 3] == false) 
        {
            visited[pos * 3] = true;
            q.push({ pos * 3, time + 1 });
        }
        if (visited[pos + _n] == false) 
        {
            visited[pos + _n] = true;
            q.push({ pos + _n, time + 1 });
        }

    }
    return -1;

}

//x는 목적 ,y는 출발,n은 뺴는값.
int solution(int x, int y, int n)
{
    return bfs(x, y, n);
}
int main()
{
    //solution(2, 5, 4);
    int a = solution(2, 5, 4);
    int b = 0;
    return 0;
}

*/