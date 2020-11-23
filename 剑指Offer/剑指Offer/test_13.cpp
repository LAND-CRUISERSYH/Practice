#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		����һ���������飬ʵ��һ�����������������������ֵ�˳��
		ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿��
		����֤������������ż����ż�������λ�ò���
*/

//1.���ٶ�������
	/*
		(1).����һ�����飬����������push����������
		(2)�ٱ���һ�����飬����ż����push����������
		(3)�������鿽����array��
	ʱ�临�Ӷ�: O(n)
	�ռ临�Ӷ�: O(n)
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


//2.�����ٶ�������
	/*
		1.��¼һ������i��ʾ�Ѿ��������źõ���һ��λ��(�ʼΪ0����ʾ��û�������ź�)
		2.jΪ�����±꣬��ʼֵΪ0����ʼ����
			�������ż����j++
			����������� �ͽ����������뵽iλ�ã��ڲ�����ǰ��Ӧ�ý�i->j-1����λ������ƶ���������ɺ�i++
	ʱ�临�Ӷ�: O(n*n)-------һ��ż��ȫ��ǰ һ������ȫ�ں�  ��ҪŲ��n/2�� һ��Ų��n/2��Ԫ�� ��Ϊ(n/2)*(n/2) = (n*n)/4
	�ռ临�Ӷ�: O(1)
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



