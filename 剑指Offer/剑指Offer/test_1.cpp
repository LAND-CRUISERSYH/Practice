#include<iostream>
#include<vector>

using namespace std;

/*
	题目描述:
		在一个二维数组中(每个一维数组的长度相同)，每一行从左到右递增，每一列从上到下递增
		请完成一个函数，输入一个这样的二维数组和一个整数，判断数组中是否含有该整数
	示例:
		输入    7，[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
		返回值 true
*/


//1.暴力算法:   直接遍历一遍数组，即可判断目标target是否存在
		//时间复杂度: O(n*n)
		//空间复杂度: O(1)
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		for (vector<vector<int>>::iterator it = array.begin(); it != array.end(); it++)
		{
			for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++)
			{
				if (target == *i)
					return true;
			}
		}
		return false;
	}
};

//2.二分查找  (从左下或右上开始找---本质一样)
/*
	以左下为例:
		左下的元素是本行最小的元素，是本列最大的元素----设为m
		当target<m时，由于m已经是该行最小的元素，想要更小只能将m移至上一行
		当target>m时，由于m已经是该列最大的元素，想要更大只能将m移至下一列
		当m=target时，返回true
	时间复杂度: O(m+n),m为行数，n为列数，最坏情况下，需要遍历m+n次
	空间复杂度: O(1)
*/

class Solution2 {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size()-1;
		int col = 0;
		while (row >= 0 && col <= (int)array[0].size())
		{
			if (target < array[row][col])
				row--;
			else if (target > array[row][col])
				col++;
			else
				return true;
		}
		return false;
	}
};

//int main()
//{
//	/*Solution s;
//	vector<vector<int>> arr = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	int temp = 7;
//	if (s.Find(temp, arr))
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;*/
//
//	Solution2 s;
//	vector<vector<int>> arr = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	int temp = 7;
//	if (s.Find(temp, arr))
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//}
