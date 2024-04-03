
//
//using namespace std;
//
//vector<int> solution(int n, long long left, long long right) {
//    std::vector<std::vector<int>> vec;
//    std::vector<int> vec1;
//    vector<int> answer;
//    vec.resize(n);
//    for (int i = 0; i < vec.size(); i++)
//    {
//        vec[i].resize(n);
//    }
//    for (int i = 0; i < vec.size(); i++)
//    {
//        for (int j = 0; j < vec[i].size();j++)
//        {
//            if (i <= j)
//            {
//                vec[i][j] = j + 1;
//            }
//            else
//            {
//                vec[i][j] = i + 1;
//            }
//        }
//    }
//    for (int i = 0; i < vec.size(); i++)
//    {
//        for (int j = 0; j < vec[i].size(); j++)
//        {
//            vec1.push_back(vec[i][j]);
//        }
//    }
//    for (long long i = left; i <= right; i++)
//    {
//        answer.push_back(vec1[i]);
//    }
//    return answer;
//}
#include <string>
#include <vector>
std::vector<int> solution(int n, long long left, long long right)
{
    std::vector<int> answer;

    for (long long i = left; i <= right; ++i)
    {
        long long X = (i % n) + 1;
        long long Y = (i / n) + 1;

        if (Y > X)
        {
            answer.push_back(Y);
        }
        else
        {
            answer.push_back(X);
        }
    }
    return answer;
}