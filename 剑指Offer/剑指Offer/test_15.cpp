#include<iostream>

using namespace std;

/*
	��Ŀ����:
		����һ������  ��ת�����   ���������ı�ͷ
	ʾ��:
		���� 123          ����ֵ 321
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
/*
	��ʼ��3��ָ��:
		preָ��ָ�����ڷ�ת��ǰһ�����(�Ѿ���ת�õ����һ�����)���ʼ��ת��ͷ��(��ͷ��ת��Ϊ��β)������preָ��nullptr
		curָ��ָ�����ڷ�ת�Ľ�㣬�ʼ��ת��ͷ������ָ���ͷ
		tempָ��ָ����һ������ת�Ľ�㣬Ŀ���Ǳ������ֹ�Ͽ�����Ϊcur�ı�ָ��󣬺����������Ҫ����
	����:
		temp = cur->next;     ����δ��ת������
		cur->next = pre;      ���ڷ�תcurָ��ָ���Ѿ���ת�õ����һ�����
		pre = cur;          ָ����ƣ�ȥ������һ������ת�Ľ�㣬��֮ǰtemp����Ľ��
		cur = temp;
	ѭ��������curΪnullptr(ҲΪѭ������������)����������preָ�룬ָ����Ƿ�ת���ͷ��㣬��cur��ǰһ�����
	ʱ�临�Ӷ�:O(n)   ����һ������
	�ռ临�Ӷ�:O(1)
*/

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead)
			return nullptr;
		ListNode* pre = nullptr;
		ListNode* cur = pHead;
		ListNode* temp = cur;
		while (cur)
		{
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};