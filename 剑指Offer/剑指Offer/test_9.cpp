#include<iostream>
#include<vector>

using namespace std;

/*
	题目描述:
		一只青蛙一次可以跳上1级台阶，也可以跳上2级.....它也可以跳上n级
		求该青蛙跳上一个n级的台阶总共有多少中跳法
	示例:    输入3     返回值4
*/

//1.递归
	/*
		第一次跳1个台阶，剩下共有f(n-1)种跳法
		第一次跳2个台阶，剩下共有f(n-2)种跳法
		...
		第一次跳n个台阶，剩下共有f(n-n)种跳法
		所以f(n)=f(n-1)+f(n-2)...+f(0)
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

//2.动态规划
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