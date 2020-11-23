#include<iostream>

using namespace std;

/*
	题目描述:
		输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示
*/

//1.除2取模法
	/*
		对于这种方法，大部分数据都是对的，但是对于-2147483648，二进制为1000....0000，一共有31个0(计算机使用补码存储二进制数据)
		根据这个方法输入-2147483648，输出为0，实际上为1，所以这种方法不对
	*/
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n != 0)
		{
			int temp = n % 2;
			if (temp == 1)
				count++;
			n = n / 2;
		}
		return count;
	}
};

//2.二进制移位法
	/*
		1.如果向右依次移动原数据，正数可以正常输出(右移最高位补0)，负数不能正常输出(右移最高位补1)
		2.可以将1依次左移，分别和原数据每一位&，如果原数据该位为1则count++，如果为0则继续左移
			时间复杂度: O(32)
			空间复杂度: O(1)
	*/
class Solution2 {
public:
	int  NumberOf1(int n) {
		int temp = 1;
		int count = 0;
		while (temp != 0)
		{
			if (temp&n)
				count++;
			temp = temp << 1;
		}
		return count;
	}
};

//3.消1法 
	/*
		举例说明:   val = 110100    val-1 = 110011   val&(val-1) = 110000
		从最右边的1开始   将它-1  之前1的位置变为0   1右边的所有0变为1(如果有的话)
		然后两个数进行&操作  就可以将之前的1消除掉   继续向左去消前面的1
		这种方法不用挨个判断  只是逐个消除1  对于正数负数道理都一样
	*/
class Solution3 {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n != 0)
		{
			++count;
			n = n & (n - 1);
		}
		return count;
	}
};