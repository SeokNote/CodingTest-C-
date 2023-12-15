#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 99999;
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == min)
        {
            continue;
        }
        else
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}
//또다른 풀이

//#include <algorithm>
//#include <vector>
//using namespace std;
//
//vector<int> solution(vector<int> arr) {
//    if (arr.size() == 1) {
//        return { -1 };
//    }
//    arr.erase(std::min_element(arr.begin(), arr.end()));
//    return arr;
//}