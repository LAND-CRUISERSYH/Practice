#include<iostream>

using namespace std;

/*
	题目描述:
		给定一个double类型的浮点数base和int类型的整数exponent.
		求base的exponent次方 (保证base和exponent不同时为0)
*/

/*
	预处理:
		如果expontent为负数   
	举例:    求x的-5次方     则可以转换成(1/x)的5次方
*/

//1.暴力求解   以exponent为循环条件 一直乘
	//时间复杂度: O(n)
	//空间复杂度: O(1)
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent < 0)
		{
			base = 1 / base;
			exponent = -exponent;
		}
		double num = 1.0;
		for (int i = 0; i < exponent; i++)
			num = num * base;
		return num;
	}
};

//2.递归法(快速幂)
/*
	假设expontent为偶数 
		例:  如果我们求x的8次方，如果我们知道x的4次方，则x的8次方为(x的4次方)的平方
		   依次类推，x的exponent次方为(x的exponent/2次方)的平方
	假设expontent为奇数
		例:  如果我们求x的7次方，则x的7次方为(x的3次方)的平方*x
			依次类推，x的exponent次方为(x的exponent/2次方)的平方*x

	时间复杂度:O(logn)          每次规模减少一半
	空间复杂度:O(logn)          递归栈，因为要记住logn个变量
*/

class Solution2 {
public:
	double func(double base, int exponent)
	{
		if (exponent == 0)
			return 1.0;
		double ret = func(base, exponent / 2);
		if (exponent & 1)
			return ret * ret*base;
		else
			return ret * ret;
	}
	double Power(double base, int exponent) {
		if (exponent < 0)
		{
			base = 1 / base;
			exponent = -exponent;
		}
		return func(base, exponent);
	}
};


//3.非递归的快速幂
/*
	假设求x的6次方   6可以用二进制表示为110
	将110向右移动     移动的同时 要将底数翻倍   (指数除2底数翻倍)  
	例 x的6次方    等于  (x的2次方)的3次方
	相当于遍历指数的二进制位，是1就乘进结果
*/

class Solution3 {
public:
	double Power(double base, int exponent) {
		if (exponent < 0)
		{
			base = 1 / base;
			exponent = -exponent;
		}
		double x = base;
		double ret = 1.0;
		while (exponent)
		{
			if (exponent & 1)
				ret = ret * x;
			x = x * x;
			exponent = exponent >> 1;
		}
		return ret;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.Power(2, 3) << endl;;
//
//	return 0;
//}