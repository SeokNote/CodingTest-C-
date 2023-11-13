#include <iostream>

int BinarySearch(int _InputTenCount)
{
	int Lt = 1;
	int Rt = 400000015;//�� ó���� INT32_MAX�� �غ��� _InputTenCount�� �ִ밪(1��)�϶� 400000015�� ���°��� Ȯ����
	int Result = 0;

	bool IsFind = false;
	while (Lt <= Rt)
	{
		int NowTenCount = 0;

		//���� �� ���丮���� �˻��ϰ� �ִ���
		int Mid = (Lt + Rt) / 2;

		//Mid ���丮�� ���Ե� 0�� ���� ���ϱ�
		for (int i = 5; i <= Mid; i *= 5)
		{
			NowTenCount += (Mid / i);
		}

		//0�� ������ ���ų� ���� ���
		if (_InputTenCount <= NowTenCount)
		{
			//0�� ������ ���� ���
			if (_InputTenCount == NowTenCount)
			{
				IsFind = true;
				Result = Mid;
			}

			Rt = (Mid - 1);
		}

		//0�� ������ ���� ���
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