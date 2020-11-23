#include<iostream>

using namespace std;

/*
	题目描述:
		大家都知道斐波那契数列，现在要求输入一个整数n
		请你输出斐波那契额数列的第n项(从0开始，第0项为0，第1项是1)  n<=39
*/

//1.递归(斐波那契数列公式:f[n]=f[n-1]+f[n-2],初始值f[0]=0,f[1]=1)
	//时间复杂度:O(2^n)
	//空间复杂度:递归栈的空间
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0 || n == 1)
			return n;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};

//2.动态规划  (不用递归的过程，直接从子树上求得答案，过程是从下往上)
	//保存前两次的求值就好
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