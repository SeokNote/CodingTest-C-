#include <iostream>
#include <queue>
bool visited[200001];
int N, K;

void bfs(int _startindex, int _endindex)
{
    std::queue<std::pair<int, int>> q;
    q.push({ _startindex,0 });
    visited[N] = 0;

    while (!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        if (pos < 0 || pos > 100000)
        {
            continue;
        }
        if (pos == _endindex)
        {
            std::cout << time;
            break;
        }
        if (visited[pos * 2] == false)
        {
            visited[pos * 2] = true;
            q.push({ pos * 2, time + 1 });
        }
        if (visited[pos + 1] == false)
        {
            visited[pos + 1] = true;
            q.push({ pos + 1, time + 1 });
        }
        if (visited[pos - 1] == false)
        {
            visited[pos - 1] = true;
            q.push({ pos - 1, time + 1 });
        }

    }

}
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    bfs(N, K);
}