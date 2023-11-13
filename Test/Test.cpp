#include <iostream>

int BinarySearch(int _InputTenCount)
{
	int Lt = 1;
	int Rt = 400000015;//맨 처음엔 INT32_MAX로 해보고 _InputTenCount이 최대값(1억)일때 400000015가 나온것을 확인함
	int Result = 0;

	bool IsFind = false;
	while (Lt <= Rt)
	{
		int NowTenCount = 0;

		//현재 몇 팩토리얼을 검사하고 있는지
		int Mid = (Lt + Rt) / 2;

		//Mid 팩토리얼에 포함된 0의 갯수 구하기
		for (int i = 5; i <= Mid; i *= 5)
		{
			NowTenCount += (Mid / i);
		}

		//0의 갯수가 많거나 같은 경우
		if (_InputTenCount <= NowTenCount)
		{
			//0의 갯수가 같은 경우
			if (_InputTenCount == NowTenCount)
			{
				IsFind = true;
				Result = Mid;
			}

			Rt = (Mid - 1);
		}

		//0의 갯수가 적은 경우
		else
		{
			Lt = (Mid + 1);
		}
	}

	return IsFind ? Result : -1;
}

int main()
{
	while (true)
	{
		int TenCount;
		std::cin >> TenCount;
		std::cout << BinarySearch(TenCount);
	}

	return 0;
}