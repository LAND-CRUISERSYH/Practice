#include<iostream>

using namespace std;

/*
	��Ŀ����:
		����һ�����ֵ�����������ʹ�ÿ⺯��
		����һλС��
	��������:
		����������Ϊdouble����(һ��ʵ��)
	�������:
		���������������������һλС��
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