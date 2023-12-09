#include<iostream>
#include<vector>
#include<queue>
std::vector<int> LinkNodes[32001];
bool Isvisit[32001];

void dfs(int _StartNode) 
{
    if (Isvisit[_StartNode] == false)
    {
        for (int i : LinkNodes[_StartNode])
        {
            if (!Isvisit[i])
            {
                dfs(i);
            }
        }
        Isvisit[_StartNode] = true;
        std::cout << _StartNode << ' ';
    }
    
}
    

int main() {
    int N = 0; // �л���
    int M = 0; //��Ƚ��
    std::queue<int> q;
    std::cin >> N >> M; 

    for (int i = 0; i < M; ++i) //��Ƚ����ŭ ��忡 ����
    {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        LinkNodes[tmp2].push_back(tmp1);
    }
    for (int i = 1; i <= N; ++i) 
    {
        if (LinkNodes[i].empty() == true) 
        {
            Isvisit[i] = true;
            std::cout << i << " ";
        }
        else
        {
            q.push(i);
        }
    }
    while (q.empty() == false) 
    {
        int node = q.front();
        q.pop();
        if (Isvisit[node] == false)
        {
            dfs(node);
        }
    }
}
