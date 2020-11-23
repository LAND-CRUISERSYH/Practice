#include<iostream>

using namespace std;

/*
	��Ŀ����:
		���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
		������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ���
	ʾ��: n=3ʱ��2*3�ľ��ο���3�ָ��Ƿ���
*/


//1.�ݹ�
class Solution {
public:
	int rectCover(int number) {
		if (number == 1 || number == 2)
			return number;
		return rectCover(number - 1) + rectCover(number - 2);
	}
};

//2
class Solution2 {
public:
	int rectCover(int number) {
		if (number == 1 || number == 2)
			return number;
		int a = 1, b = 2, c = 0;
		for (int i = 3; i <= number; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};