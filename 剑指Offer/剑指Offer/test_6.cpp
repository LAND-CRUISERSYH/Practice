#include<iostream>
#include<vector>

using namespace std;

/*
	题目描述:
		把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
		输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素
		NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
*/


//1.直接遍历一遍数组，即可找到最小值
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int min = rotateArray[0];
		for (int i = 1; i < rotateArray.size(); i++)
		{
			if (min > rotateArray[i])
				min = rotateArray[i];
		}
		return min;
	}
};

//2.二分查找(原数组任意区间非递减)
	//非递减排序的数组可能为递增数组或者有重复数字的递增数组
	//旋转后以最小值为分界点 左边的序列中任意元素都>=右边序列中的元素
	//要求最小元素分三种情况(取mid为中间值)
		/*
			1.mid>右边序列最大的值   则最小值在mid+1  和   last之间
			2.mid<右边序列最大的值   则最小值在first  和   mid(包含mid)之间
			3.mid == 右边序列的值 10111 / 11101   则将last--  缩小范围  
		*/

class Solution2 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int first = 0;
		int last = rotateArray.size() - 1;
		while (first < last)
		{
			if (rotateArray[first] < rotateArray[last])
				return rotateArray[first];
			int mid = first + (last - first) / 2;
			if (rotateArray[mid] > rotateArray[last])   //情况1
				first = mid + 1;
			else if (rotateArray[mid] < rotateArray[last])  //情况2
				last = mid;
			else                   //情况3
				last--;
		}
		return rotateArray[first];
	}
};