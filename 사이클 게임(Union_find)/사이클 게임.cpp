#include <iostream>
#include <vector>

int N, M;
std::vector<int> Parent;

void Union(int _Left, int _Right)
{
	if (_Left < _Right)
	{
		Parent[_Right] = _Left;
	}
	else
	{
		Parent[_Left] = _Right;
	}
}
//�θ� ��ȯ
int FindParent(int _Num)
{
	if (Parent[_Num] == _Num)
	{
		return _Num;
	}

	Parent[_Num] = FindParent(Parent[_Num]);
	return Parent[_Num];
}

int main()
{
	std::cin >> N >> M;
	Parent.resize(N + 1);
	//�ڱ� �ڽ��� �θ�� �д�.
	for (int i = 1; i <= N; i++)
	{
		Parent[i] = i;
	}
	//�ϳ��� �����ϸ鼭 �θ� ����
	for (int i = 1; i <= M; i++)
	{
		int LinkNode1, LinkNode2;
		std::cin >> LinkNode1 >> LinkNode2;
		//���� 0, 1�� �Է¹ް� 1,2�� �Է¹����� 1, 2�� 1�� �θ�� 0�̹Ƿ�  0 , 2�� �ȴ�.
		int FirstParent = FindParent(LinkNode1);
		int SecondParent = FindParent(LinkNode2);
		//�θ� ���� �Ǹ� ����Ŭ�� �̹Ƿ� ����
		if (FirstParent != SecondParent)
		{
			Union(FirstParent, SecondParent);
		}
		else
		{
			std::cout << i;
			return 0;
		}
	}

	std::cout << 0;
	return 0;
}