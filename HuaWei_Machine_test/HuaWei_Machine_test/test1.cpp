#include<iostream>

using namespace std;

/*
	题目描述:
		正整数A和正整数B的最小公倍数是指能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数
	输入描述:
		输入两个正整数A和B
	输出描述:
		输出A和B的最小公倍数
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