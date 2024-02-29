#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N = 0;
    std::cin >> N;

    std::vector<int> vec;
    std::vector<int> answer(2);
    vec.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int Num = 0;
        std::cin >> Num;
        vec.push_back(Num);
    }
    std::sort(vec.begin(), vec.end());
    int start = 0;
    int end = N - 1;
    int min = INT32_MAX;

    while (start < end) {
        int sum = vec[start] + vec[end];

        if (abs(sum) < min) {
            answer[0] = vec[start];
            answer[1] = vec[end];
            min = abs(sum);
        }

        if (sum < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }


    std::cout << answer[0] << " " << answer[1];


    return 0;
}