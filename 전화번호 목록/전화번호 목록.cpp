#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        std::cin >> M;
        std::vector<std::string> vec;
        vec.resize(M);
        for (int j = 0; j < M; j++)
        {
            std::string str = "";
            std::cin >> str;
            vec[j] = str;
        }

        std::sort(vec.begin(), vec.end());
        bool IsValue = false;
        for (int t = 0; t < M - 1; t++)
        {
            std::string str1 = vec[t];
            std::string str2 = vec[t + 1];

            if (str1 == str2.substr(0, str1.size()))
            {
                std::cout << "NO" << std::endl;
                IsValue = true;
                break;
            }

        }
        if (IsValue == false)
        {
            std::cout << "YES" << std::endl;
        }
    }

}