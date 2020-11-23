#include<iostream>

using namespace std;

/*
	��Ŀ����:
		��Ҷ�֪��쳲��������У�����Ҫ������һ������n
		�������쳲����������еĵ�n��(��0��ʼ����0��Ϊ0����1����1)  n<=39
*/

//1.�ݹ�(쳲��������й�ʽ:f[n]=f[n-1]+f[n-2],��ʼֵf[0]=0,f[1]=1)
	//ʱ�临�Ӷ�:O(2^n)
	//�ռ临�Ӷ�:�ݹ�ջ�Ŀռ�
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0 || n == 1)
			return n;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};

//2.��̬�滮  (���õݹ�Ĺ��̣�ֱ�Ӵ���������ô𰸣������Ǵ�������)
	//����ǰ���ε���ֵ�ͺ�
class Solution2 {
public:
	int Fibonacci(int n) {
		if (n == 0 || n == 1)
			return n;
		int a = 0, b = 1, c = 0;
		for (int i = 2; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};

//int main()
//{
//	Solution2 s;
//	cout << s.Fibonacci(5) << endl;;
//	return 0;
//}