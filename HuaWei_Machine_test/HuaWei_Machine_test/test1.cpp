#include<iostream>

using namespace std;

/*
	��Ŀ����:
		������A��������B����С��������ָ�ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С������
	��������:
		��������������A��B
	�������:
		���A��B����С������
*/

int func(int a, int b)
{
	if (a == b)
		return a;
	int Max = (a > b) ? a : b;
	int Min = (a > b) ? b : a;

	if (Max%Min == 0)
		return Max;
	else
	{
		while (1)
		{
			if (Max%a == 0 && Max%b == 0)
				return Max;
			else
				Max++;
		}
	}
}

//int main()
//{
//	int a, b;
//	cin >> a;
//	cin >> b;
//	cout << func(a, b) << endl;
//	return 0;
//}