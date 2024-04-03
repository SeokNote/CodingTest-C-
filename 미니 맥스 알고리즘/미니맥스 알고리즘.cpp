#include <string>
#include <vector>


using namespace std;

// ��ǥ�� ��Ÿ���� ����ü
struct Point 
{
    int x, y;
};
vector<vector<int>> map; // ���� üũ

int n, m; // n : ����, m : ����

// �����¿�
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

// me : ���� ���� ��� // you : ����
int dfs(Point me, Point you) {
    int x = me.x;
    int y = me.y;

    // ������ ������ٸ� 0 ��ȯ
    if (map[x][y] == 0)
    {
        return 0;
    }

    int result = 0; // �������� �� ��
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0)
        {
            continue;
        }

        map[x][y] = 0; // ���� ���ִ� ���� �̵� �Ұ����ϰ� ���� 

        // ���⼭ ���� ���̱� ������ �Ű������� dfs(you,me) ������ ����.
        int val = dfs(you, { nx,ny }) + 1; // �� �� + 1
        map[x][y] = 1; // ����Ѱ��� ���� ����

        // ���ݱ��� ��� �� ����, �̹��� �̰��� ��
        if (val % 2 == 1 && result % 2 == 0)
        { 
            // �ٷ� �̱�ɷ� �ٲ���
            result = val;
        }
        // ���ݱ����� ����, �� ��쵵 �� ��� -> �ִ��� ���� �����δ�.
        else if (val % 2 == 0 && result % 2 == 0) 
        {
            result = max(result, val);
        }
        // ���ݱ����� �̰��, �� ��쵵 �̱� ��� -> �ִ��� ���� �����δ�.
        else if (val % 2 == 1 && result % 2 == 1)
        {
            result = min(result, val);
        }
    }

    return result;
}