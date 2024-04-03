//#include <string>
//#include <vector>
//using namespace std;
//
//vector<int> solution(vector<int> sequence, int k) {
//    vector<int> answer;
//    vector<vector<std::pair<int,int>>> vec;
//    vector<int> counts;
//    vec.resize(1001);
//    for (int i = 0; i < sequence.size(); i++)
//    {
//        int sum = 0;
//        int count = 0;
//        for (int j = i; j < sequence.size(); j++)
//        {
//            count++;
//            sum += sequence[j];
//            if (sum == k)
//            {
//                //count는 배열 갯수 i = 시작 인덱스 j는 마지막 인덱스
//                counts.push_back(count);
//                vec[count].push_back(make_pair(i, j));
//                count = 0;
//                sum = 0;
//            }
//        }
//    }
//    std::sort(counts.begin(), counts.end());
//    answer.push_back(vec[counts[0]][0].first);
//    answer.push_back(vec[counts[0]][0].second);
//    return answer;
//}
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
	answer.resize(2);
	int right = 0;
	int result = k;
	int min = 100000000;
	int sum = 0;
	for (int left = 0; left < sequence.size(); left++)
	{

		while (sum < k && right<sequence.size())
		{
			sum += sequence[right];
			right++;
		}
		if (sum == k)
		{
			if (min > right - left)
			{
				min = right - left;
				answer[0] = left;
				answer[1] = right - 1;
			}

		}
		sum -= sequence[left];
	}
    return answer;
}
int main()
{
    solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);
	int N = 0;
	

}