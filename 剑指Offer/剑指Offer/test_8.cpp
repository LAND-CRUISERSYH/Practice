#include<iostream>

using namespace std;

/*
	��Ŀ����:
		һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
		�����������һ��n��̨���ܹ��ж���������(�Ⱥ����ͬ�㲻ͬ�Ľ��)
	ʾ��:
		����1    ����ֵ1
		����4    ����ֵ5
*/

//1.�ݹ�
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1 || number == 2)
			return number;
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};

//2.��̬�滮
class Solution2 {
public:
	int jumpFloor(int number) {
		if (number == 1 || number == 2)
			return number;
		int a = 1, b = 2, c = 0;
		for (int i = 2; i < number; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};