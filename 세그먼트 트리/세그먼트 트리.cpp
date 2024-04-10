#include <iostream>
#include <vector>
#include <cmath>
// arr: 초기 배열
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
long long init(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) 
{
    // 노드가 리프 노드인 경우
    if (start == end)
    {
        // 배열의 그 원소를 가져야 함
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    // 구간 합을 구하는 경우
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);

    // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.
    // return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}
long long sum(std::vector<long long>& tree, int node, int start, int end, int left, int right)
{
    // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우,
    // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
    if (left > end || right < start)
    {
        return 0;
    };

    // case 2: [start, end]가 [left, right]에 포함
    if (left <= start && end <= right)
    {
        return tree[node];
    };

    // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(std::vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
    // case 2 [start, end] 에 index가 포함되지 않는 경우
    if (index < start || index > end)
    {
        return;
    }
    // case 1 [start, end] 에 index가 포함된 경우
    tree[node] = tree[node] + diff;

    // 리프 노드가 아닌 경우 자식도 변경해줘야 하기 때문에,
    // 리프 노드인지 검사를 하고 아래 자식 노드를 갱신해준다.
    if (start != end)
    {
        long long mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
    return;
}

int main()
{
    int N, M, K;
    std::vector<long long> arr;
    std::vector<long long> tree;
    std::vector<long long> answer;
    std::cin >> N >> M >> K;

    int h = static_cast<int>(std::ceil(std::log2(N)));
    int tree_size = (1 << (h + 1));

    arr.resize(N);
    tree.resize(tree_size);
    answer.reserve(K);
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    init(arr, tree, 1, 0, N - 1);
    for (int i = 0; i < M + K; i++)
    {
        int a, b;
        std::cin >> a >> b;
        long long c;
        std::cin >> c;
        b--;

        if (a == 1)
        {
            long long diff = c - arr[b];
            arr[b] = c;
            update(tree, 1, 0, N - 1, b, diff);
        }
        else if (a == 2)
        {
            c--;
            answer.push_back(sum(tree, 1, 0, N - 1, b, c));
        }
    }
    for (int i = 0; i < K; i++)
    {
        std::cout << answer[i] << "\n";
    }

    return 0;
}