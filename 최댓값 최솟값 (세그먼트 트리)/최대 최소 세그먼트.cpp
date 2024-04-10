#include <iostream>
#include <vector>
#include <cmath>
// arr: 초기 배열
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
std::vector<long long> arr;
std::vector<long long> tree;
std::vector<long long> min_tree;
std::vector<long long> max_tree;

long long mininit(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) {
    // 노드가 리프 노드인 경우
    if (start == end)
    {
        // 배열의 그 원소를 가져야 함
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

     return tree[node] = std::min(mininit(arr, tree, node * 2, start, mid), mininit(arr, tree, node * 2 + 1, mid + 1, end));
}
long long maxinit(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) {
    // 노드가 리프 노드인 경우
    if (start == end)
    {
        // 배열의 그 원소를 가져야 함
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = std::max(maxinit(arr, tree, node * 2, start, mid), maxinit(arr, tree, node * 2 + 1, mid + 1, end));
}

long long QueryMax(std::vector<long long>& tree, int node, int start, int end, int left, int right)
{

    if (left > end || right < start)
    {
        return INT32_MIN;
    };

    if (left <= start && end <= right)
    {
        return tree[node];
    };

    int mid = (start + end) / 2;
    return std::max(QueryMax(tree, node * 2, start, mid, left, right),QueryMax(tree, node * 2 + 1, mid + 1, end, left, right));
}

long long QueryMin(std::vector<long long>& tree, int node, int start, int end, int left, int right)
{

    if (left > end || right < start)
    {
        return INT32_MAX;
    };

    if (left <= start && end <= right)
    {
        return tree[node];
    };

    int mid = (start + end) / 2;
    return std::min(QueryMin(tree, node * 2, start, mid, left, right), QueryMin(tree, node * 2 + 1, mid + 1, end, left, right));
}

void update(std::vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
    if (index < start || index > end)
    {
        return;
    }
    tree[node] = tree[node] + diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main()
{
    int N, M;

    std::cin >> N >> M;
    std::vector<std::pair<long long, long long>> answer;
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));

    arr.resize(N + 1);
    tree.resize(tree_size);
    min_tree.resize(tree_size);
    max_tree.resize(tree_size);
    for (int i = 0; i < min_tree.size(); i++)
    {
        min_tree[i] = INT32_MAX;
        max_tree[i] = INT32_MIN;
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    mininit(arr, min_tree, 1, 0, N - 1);
    for (int i = 0; i < M; i++)
   {
       int a, b;
       std::cin >> a >> b;
       a--;
       b--;
       answer.(QueryMin(min_tree,1,0,N-1,a, b));
   }
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i].first<<" " << answer[i].second << "\n";
    }
    int a = 0;
    return 0;
}