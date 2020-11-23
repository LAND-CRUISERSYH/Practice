#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
		����һ���ǵݼ�����������һ����ת�������ת�������СԪ��
		NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0
*/


//1.ֱ�ӱ���һ�����飬�����ҵ���Сֵ
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

//2.���ֲ���(ԭ������������ǵݼ�)
	//�ǵݼ�������������Ϊ��������������ظ����ֵĵ�������
	//��ת������СֵΪ�ֽ�� ��ߵ�����������Ԫ�ض�>=�ұ������е�Ԫ��
	//Ҫ����СԪ�ط��������(ȡmidΪ�м�ֵ)
		/*
			1.mid>�ұ���������ֵ   ����Сֵ��mid+1  ��   last֮��
			2.mid<�ұ���������ֵ   ����Сֵ��first  ��   mid(����mid)֮��
			3.mid == �ұ����е�ֵ 10111 / 11101   ��last--  ��С��Χ  
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
			if (rotateArray[mid] > rotateArray[last])   //���1
				first = mid + 1;
			else if (rotateArray[mid] < rotateArray[last])  //���2
				last = mid;
			else                   //���3
				last--;
		}
		return rotateArray[first];
	}
};