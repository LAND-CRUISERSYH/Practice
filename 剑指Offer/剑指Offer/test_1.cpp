#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		��һ����ά������(ÿ��һά����ĳ�����ͬ)��ÿһ�д����ҵ�����ÿһ�д��ϵ��µ���
		�����һ������������һ�������Ķ�ά�����һ���������ж��������Ƿ��и�����
	ʾ��:
		����    7��[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
		����ֵ true
*/


//1.�����㷨:   ֱ�ӱ���һ�����飬�����ж�Ŀ��target�Ƿ����
		//ʱ�临�Ӷ�: O(n*n)
		//�ռ临�Ӷ�: O(1)
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

//2.���ֲ���  (�����»����Ͽ�ʼ��---����һ��)
/*
	������Ϊ��:
		���µ�Ԫ���Ǳ�����С��Ԫ�أ��Ǳ�������Ԫ��----��Ϊm
		��target<mʱ������m�Ѿ��Ǹ�����С��Ԫ�أ���Ҫ��Сֻ�ܽ�m������һ��
		��target>mʱ������m�Ѿ��Ǹ�������Ԫ�أ���Ҫ����ֻ�ܽ�m������һ��
		��m=targetʱ������true
	ʱ�临�Ӷ�: O(m+n),mΪ������nΪ�����������£���Ҫ����m+n��
	�ռ临�Ӷ�: O(1)
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
