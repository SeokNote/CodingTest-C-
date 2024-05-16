#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> cards;
std::vector<std::vector<int>> numbers;
std::vector<int> number;
std::vector<int> answers;
int answer = 0;

bool continuityNumberCheck(std::vector<int>& _numbers)
{
	int cnt = 0;
	std::sort(_numbers.begin(), _numbers.end());
	int startnum = _numbers[0];
	for (int i = 1; i < 5; i++)
	{
		if (startnum +i == _numbers[i])
		{
			cnt++;
		}
	}
	if (cnt == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void solution()
{

	//카드 색이 얼마나 같은지는 알 수 있음
	//5장중 4장의 숫자가 같을 때 같은 숫자에 800 더하기 
	//5장중 3장의 숫자가 같고 나머지 2장의 숫자가 같을 때
	//5장의 카드의 숫자가 연속적일 떄
	//5장의 카드중 3장의 숫자가 같을 때
	//5장중 2장의 숫자가 같고 나머지 2장의 숫자가 같을 때
	//5장중 2장의 숫자가 같을 때
	//아니면 가장 큰 숫자에 100 더하기.

	//일단 5장의 카드가 모두 같은 색 일때
	for (int i = 0; i < 4; i++)
	{
		//5장의 카드가 모두 같은 색 일 때
		if (cards[i].size() == 5)
		{
			std::sort(cards[i].begin(), cards[i].end());
			//카드색이 모두 같고 연속적인 수일 때
			if (continuityNumberCheck(cards[i]))
			{
				answer = 900 + cards[i][4];
				answers.push_back(answer);
			}
			answer = 600 + cards[i][4];
			answers.push_back(answer);
			
		}
	}
	for (int i = 1; i < 10; i++)
	{
		// 카드 5장중 4장의 숫자가 같을 때
		if (numbers[i].size() == 4)
		{
			answer = i + 800;
			answers.push_back(answer);
		}
		// 카드 5장중 3장의 카드가 같을 때
		else if (numbers[i].size() == 3)
		{
			//나머지 2장 체크
			int cnt = 0;
			int num = 0;
			for (int j = 0; j < 5; j++)
			{
				if (number[j] != i)
				{
					if (num == number[j])
					{
						cnt++;
					}
					num = number[j];
					
				}
				else
				{
					continue;
				}
			}
			//2장 같음
			if (cnt == 1)
			{
				answer = (i * 10) + num + 700;
				answers.push_back(answer);
			}
			answer = i + 400;
			answers.push_back(answer);
			
		}
		else if (numbers[i].size() == 2)
		{
			for (int j = 1; j < 10; j++)
			{
				if (numbers[j].size() == 2 && j != i)
				{
					if (j > i)
					{
						answer = (j * 10) + i + 300;
						answers.push_back(answer);
					}
					else
					{
						answer = (i * 10) + j + 300;
						answers.push_back(answer);
					}
				}
			}
			answer = i + 200;
			answers.push_back(answer);
		}
	}
	//5장의 카드가 연속적일 떄
	if (continuityNumberCheck(number) == true)
	{
		answers.push_back(number[4] + 500);
	}


}
int main()
{

	cards.resize(4);
	numbers.resize(10);
	number.reserve(5);

	//0은 빨간색 1은 파란색 2는 노랜색 3은 녹색
	for (int i = 0; i < 5; i++)
	{
		int num;
		char ch;
		std::cin >> ch;
		std::cin >> num;
		if (ch == 'B')
		{
			cards[1].push_back(num);
			numbers[num].push_back(num);
			number.push_back(num);
		}
		else if (ch == 'R')
		{
			cards[0].push_back(num);
			numbers[num].push_back(num);
			number.push_back(num);
		}
		else if (ch == 'Y')
		{
			cards[2].push_back(num);
			numbers[num].push_back(num);
			number.push_back(num);
		}
		else if (ch == 'G')
		{
			cards[3].push_back(num);
			numbers[num].push_back(num);
			number.push_back(num);
		}
	}
	solution();
	if (answers.size() == 0)
	{
		answer = number[4] + 100;
		answers.push_back(answer);
	}
	std::sort(answers.begin(), answers.end(),std::greater<int>());
	std::cout << answers[0];
	return 0;
}