#include <iostream>
#include <vector>
#include <algorithm>
/*
* 1년간의 인사고과에 따라 인센티브 지급
* 근무 태도 점수 , 동료 평가 점수 기록
* 임의의 다른 사원보다 이 두점수가 낮으면 인센티브x
* 그렇지 않으면 높은 순으로 인센티브 지급
* 두 점수의 합이 동일하면 동석차
* 동석차 수만큼 다음 석차는 건너뜀
*/
std::vector<std::pair<int, int>> Arr;

bool Compare(std::pair<int, int> _a, std::pair<int, int> _b)
{
	return _a.first < _b.first;
}

bool SumCompare(std::pair<int, int> _a, std::pair<int, int> _b)
{
	int Total1 = _a.first + _a.second;
	int Total2 = _b.first + _b.second;
	return Total1 < Total2;
}

int solution(std::vector<std::vector<int>> scores)
{
	bool WanhoValue = false;
	int answer = 0;
	int WanhoScore1 = scores[0][0];
	int WanhoScore2 = scores[0][1];
	Arr.resize(scores.size());
	for (int i = 0; i < scores.size(); i++)
	{
		Arr[i].first = scores[i][0];
		Arr[i].second = scores[i][1];
	}

	std::sort(Arr.begin(), Arr.end(), Compare);
	//검열
	for (int i = 0; i < Arr.size(); i++)
	{
		bool Value = false;
		for (int j = i; j < Arr.size()-1; j++)
		{
			if (Arr[i].second < Arr[j + 1].second && Arr[i].first < Arr[j + 1].first)
			{
				if (Arr[i].first == WanhoScore1 && Arr[i].second == WanhoScore2)
				{
					return -1;
				}
				Arr.erase(Arr.begin() + i);
				Value = true;
			}
		}
		if (Value == true)
		{
			i--;
		}
	}
	std::sort(Arr.begin(), Arr.end(), SumCompare);
	int MaxScore = 0;
	int Cnt = 0;
	int JumCnt = 0;
	for (int i = Arr.size() - 1; i >= 0; i--)
	{
		int TotalScore = Arr[i].first + Arr[i].second;
		if (MaxScore == TotalScore)
		{
			JumCnt++;
		}
		else
		{
			Cnt = Cnt + JumCnt + 1;
			JumCnt = 0;
		}
		if (Arr[i].first == WanhoScore1 && Arr[i].second == WanhoScore2)
		{
			answer = Cnt;
		}
		MaxScore = TotalScore;

	}

	return answer;
}
int main()
{
	std::cout << solution({ {1,1 }, { 1, 1 }, {1, 1 }, { 1, 1 } });
	return 0;
}