#include<iostream>
#include<vector>

using namespace std;

/*
	题目描述:
		输入一个整数数组，实现一个函数来调整该数组中数字的顺序
		使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分
		并保证奇数和奇数，偶数和偶数的相对位置不变
*/

//1.开辟额外数组
	/*
		(1).遍历一遍数组，遇到奇数就push到新数组中
		(2)再遍历一遍数组，遇到偶数就push到新数组中
		(3)将新数组拷贝到array中
	时间复杂度: O(n)
	空间复杂度: O(n)
	*/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> v;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2)
				v.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2==0)
				v.push_back(array[i]);
		}
		array = v;
	}
};


//2.不开辟额外数组
	/*
		1.记录一个变量i表示已经将奇数放好的下一个位置(最开始为0，表示还没有奇数放好)
		2.j为数组下标，初始值为0，开始遍历
			如果遇到偶数就j++
			如果遇到奇数 就将该奇数插入到i位置，在插入在前，应该将i->j-1区间位置向后移动，插入完成后将i++
	时间复杂度: O(n*n)-------一半偶数全在前 一半奇数全在后  需要挪动n/2次 一次挪动n/2个元素 则为(n/2)*(n/2) = (n*n)/4
	空间复杂度: O(1)
	*/
class Solution2 {
public:
	void reOrderArray(vector<int> &array) {
		int i = 0;
		for (int j = 0; j < array.size(); j++)
		{
			if (array[j] & 1)
			{
				int temp = array[j];
				for (int k = j - 1; k >= i; k--)
					array[k + 1] = array[k];
				array[i++] = temp;
			}
		}
	}
};



