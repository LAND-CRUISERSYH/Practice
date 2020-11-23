#include<iostream>

using namespace std;

/*
	��Ŀ����:
		����һ��double���͵ĸ�����base��int���͵�����exponent.
		��base��exponent�η� (��֤base��exponent��ͬʱΪ0)
*/

/*
	Ԥ����:
		���expontentΪ����   
	����:    ��x��-5�η�     �����ת����(1/x)��5�η�
*/

//1.�������   ��exponentΪѭ������ һֱ��
	//ʱ�临�Ӷ�: O(n)
	//�ռ临�Ӷ�: O(1)
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent < 0)
		{
			base = 1 / base;
			exponent = -exponent;
		}
		double num = 1.0;
		for (int i = 0; i < exponent; i++)
			num = num * base;
		return num;
	}
};

//2.�ݹ鷨(������)
/*
	����expontentΪż�� 
		��:  ���������x��8�η����������֪��x��4�η�����x��8�η�Ϊ(x��4�η�)��ƽ��
		   �������ƣ�x��exponent�η�Ϊ(x��exponent/2�η�)��ƽ��
	����expontentΪ����
		��:  ���������x��7�η�����x��7�η�Ϊ(x��3�η�)��ƽ��*x
			�������ƣ�x��exponent�η�Ϊ(x��exponent/2�η�)��ƽ��*x

	ʱ�临�Ӷ�:O(logn)          ÿ�ι�ģ����һ��
	�ռ临�Ӷ�:O(logn)          �ݹ�ջ����ΪҪ��סlogn������
*/

class Solution2 {
public:
	double func(double base, int exponent)
	{
		if (exponent == 0)
			return 1.0;
		double ret = func(base, exponent / 2);
		if (exponent & 1)
			return ret * ret*base;
		else
			return ret * ret;
	}
	double Power(double base, int exponent) {
		if (exponent < 0)
		{
			base = 1 / base;
			exponent = -exponent;
		}
		return func(base, exponent);
	}
};


//3.�ǵݹ�Ŀ�����
/*
	������x��6�η�   6�����ö����Ʊ�ʾΪ110
	��110�����ƶ�     �ƶ���ͬʱ Ҫ����������   (ָ����2��������)  
	�� x��6�η�    ����  (x��2�η�)��3�η�
	�൱�ڱ���ָ���Ķ�����λ����1�ͳ˽����
*/

class Solution3 {
public:
	double Power(double base, int exponent) {
		if (exponent < 0)
		{
			base = 1 / base;
			exponent = -exponent;
		}
		double x = base;
		double ret = 1.0;
		while (exponent)
		{
			if (exponent & 1)
				ret = ret * x;
			x = x * x;
			exponent = exponent >> 1;
		}
		return ret;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.Power(2, 3) << endl;;
//
//	return 0;
//}