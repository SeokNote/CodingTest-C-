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

	//ī�� ���� �󸶳� �������� �� �� ����
	//5���� 4���� ���ڰ� ���� �� ���� ���ڿ� 800 ���ϱ� 
	//5���� 3���� ���ڰ� ���� ������ 2���� ���ڰ� ���� ��
	//5���� ī���� ���ڰ� �������� ��
	//5���� ī���� 3���� ���ڰ� ���� ��
	//5���� 2���� ���ڰ� ���� ������ 2���� ���ڰ� ���� ��
	//5���� 2���� ���ڰ� ���� ��
	//�ƴϸ� ���� ū ���ڿ� 100 ���ϱ�.

	//�ϴ� 5���� ī�尡 ��� ���� �� �϶�
	for (int i = 0; i < 4; i++)
	{
		//5���� ī�尡 ��� ���� �� �� ��
		if (cards[i].size() == 5)
		{
			std::sort(cards[i].begin(), cards[i].end());
			//ī����� ��� ���� �������� ���� ��
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
		// ī�� 5���� 4���� ���ڰ� ���� ��
		if (numbers[i].size() == 4)
		{
			answer = i + 800;
			answers.push_back(answer);
		}
		// ī�� 5���� 3���� ī�尡 ���� ��
		else if (numbers[i].size() == 3)
		{
			//������ 2�� üũ
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
			//2�� ����
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
	//5���� ī�尡 �������� ��
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

	//0�� ������ 1�� �Ķ��� 2�� �뷣�� 3�� ���
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