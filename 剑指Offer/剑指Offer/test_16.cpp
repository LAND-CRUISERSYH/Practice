#include<iostream>

using namespace std;

/*
	��Ŀ����:
		���������������������������������ϳɺ������
		��Ȼ������Ҫ�ϳɺ���������㵥����������
	ʾ��:
		����{1,3,5}   {2,4,6}
		����ֵ{1,2,3,4,5,6}
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1 || !pHead2)
			return nullptr;
		ListNode* temp = nullptr;;
		while (pHead1 || pHead2)
		{
			if (pHead1->val >= pHead2->val)
			{

			}
		}
	}
};