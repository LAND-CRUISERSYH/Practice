#include<iostream>

using namespace std;

/*
	题目描述:
		一只青蛙一次可以跳上1级台阶，也可以跳上2级。
		求该青蛙跳上一个n级台阶总共有多少种跳法(先后次序不同算不同的结果)
	示例:
		输入1    返回值1
		输入4    返回值5
*/

//1.递归
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1 || number == 2)
			return number;
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};

//2.动态规划
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