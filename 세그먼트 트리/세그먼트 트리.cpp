#include <iostream>
#include <vector>
#include <cmath>
// arr: �ʱ� �迭
// tree: ���׸�Ʈ Ʈ��
// node: ���׸�Ʈ Ʈ�� ��� ��ȣ
// node�� ����ϴ� ���� ������ start ~ end
long long init(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) 
{
    // ��尡 ���� ����� ���
    if (start == end)
    {
        // �迭�� �� ���Ҹ� ������ ��
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    // ���� ���� ���ϴ� ���
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);

    // ������ �ּڰ��� ���ϴ� ��쵵 ����ϰ� ���� �� �ִ�.
    // return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}
long long sum(std::vector<long long>& tree, int node, int start, int end, int left, int right)
{
    // case 1: [start, end] �� �ڿ� [left, right]�� �ִ� ���,
    // ��ġ�� �ʱ� ������ Ž���� �� �̻� �� �ʿ䰡 ����.
    if (left > end || right < start)
    {
        return 0;
    };

    // case 2: [start, end]�� [left, right]�� ����
    if (left <= start && end <= right)
    {
        return tree[node];
    };

    // case 3, 4: ���� �ڽİ� ������ �ڽ��� ��Ʈ�� �ϴ� Ʈ������ �ٽ� Ž�� ����
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(std::vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
    // case 2 [start, end] �� index�� ���Ե��� �ʴ� ���
    if (index < start || index > end)
    {
        return;
    }
    // case 1 [start, end] �� index�� ���Ե� ���
    tree[node] = tree[node] + diff;

    // ���� ��尡 �ƴ� ��� �ڽĵ� ��������� �ϱ� ������,
    // ���� ������� �˻縦 �ϰ� �Ʒ� �ڽ� ��带 �������ش�.
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