#include<iostream>

using namespace std;

/*
	题目描述:
		计算一个数字的立方根，不使用库函数
		保留一位小数
	输入描述:
		待求解参数，为double类型(一个实数)
	输出描述:
		输入参数的立方根，保留一位小数
*/

int main()
{
	double i;
	cin >> i;
	double x = 0;
	int flag = 0;
	if (i >= 0)
		flag = 1;
	else
		flag = -1;
	while (x*x*x < (i*flag))
		x += 0.01;
	printf("%.1f", x*flag);
	return 0;
}