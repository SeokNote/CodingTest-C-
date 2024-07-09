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
//부모를 반환
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
	//자기 자신을 부모로 둔다.
	for (int i = 1; i <= N; i++)
	{
		Parent[i] = i;
	}
	//하나씩 연결하면서 부모 갱신
	for (int i = 1; i <= M; i++)
	{
		int LinkNode1, LinkNode2;
		std::cin >> LinkNode1 >> LinkNode2;
		//만약 0, 1이 입력받고 1,2가 입력받으면 1, 2중 1의 부모는 0이므로  0 , 2가 된다.
		int FirstParent = FindParent(LinkNode1);
		int SecondParent = FindParent(LinkNode2);
		//부모가 같게 되면 사이클이 이므로 리턴
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