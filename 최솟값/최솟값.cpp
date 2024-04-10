#include <iostream>
#include <vector>
#include <cmath>

long long mininit(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) {
    int mid = (start + end) / 2;

    if (start == end)
    {
        return tree[node] = arr[start];
    }
    else
    {
        return tree[node] = std::min(mininit(arr, tree, node * 2, start, mid), mininit(arr, tree, node * 2 + 1, mid + 1, end));
    }

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

int main()
{
    int N, M;

    std::cin >> N >> M;
    std::vector<long long> arr;
    std::vector<long long> tree;
    std::vector<long long> min_tree;
    std::vector<long long> answer;

    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));

    arr.resize(N + 1);
    tree.resize(tree_size);
    min_tree.resize(tree_size);

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
        answer.push_back(QueryMin(min_tree, 1, 0, N - 1, a, b));
    }

    for (int i = 0; i < M; i++)
    {
        std::cout << answer[i] << "\n";
    }
    return 0;
}