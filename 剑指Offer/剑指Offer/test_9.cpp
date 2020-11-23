#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		һֻ����һ�ο�������1��̨�ף�Ҳ��������2��.....��Ҳ��������n��
		�����������һ��n����̨���ܹ��ж���������
	ʾ��:    ����3     ����ֵ4
*/

//1.�ݹ�
	/*
		��һ����1��̨�ף�ʣ�¹���f(n-1)������
		��һ����2��̨�ף�ʣ�¹���f(n-2)������
		...
		��һ����n��̨�ף�ʣ�¹���f(n-n)������
		����f(n)=f(n-1)+f(n-2)...+f(0)
		    f(n-1) = f(n-2)+f(n-3)...+f(0)
			f(n) = 2*f(n-1)
	*/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return -1;
		else if (number == 1)
			return 1;
		else
			return 2 * jumpFloorII(number - 1);
	}
};

//2.��̬�滮
class Solution2 {
public:
	int jumpFloorII(int number) {
		vector<int> f(number+1,0);
		f[1] = 1;
		f[2] = 2;
		for (int i = 3; i <= number; i++)
			f[i] = 2 * f[i - 1];
		return f[number];
	}
};