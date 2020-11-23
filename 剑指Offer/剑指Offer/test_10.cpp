#include<iostream>

using namespace std;

/*
	题目描述:
		我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
		请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法
	示例: n=3时，2*3的矩形块有3种覆盖方法
*/


//1.递归
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