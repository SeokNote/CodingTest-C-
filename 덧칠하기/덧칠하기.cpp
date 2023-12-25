#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 1;

	int paint = section[0] + m;
	for (int i = 1; i < section.size(); i++)
	{
		if (section[i] < paint)
		{
			continue;
		}
		else {
			paint = section[i] + m;
			answer++;
		}
	}

	return answer;
}