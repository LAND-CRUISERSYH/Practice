#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		����һ����������������е�����k�����
	ʾ��:
		���� 1 2 3 4 5    ����  1
		���   5
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//1.��ͨ�ⷨ
	/*
		����������K����㣬������Ӧ�ô�ͷ���������n-k��(nΪ�ܽ�����)
		�� �ܹ���6�����  ������3��  (4) 
				1 2 3 4 5 6   ��Ӧ�ô�ͷ���������next3��
		����Ҫע������ϸ��
			k<=0����ͷ����ʼ��Ϊ��
			�����ܸ���<k
		ʱ�临�Ӷ�:  O(2*n)  �������������һ����㣬��ô��Ҫ������������
		�ռ临�Ӷ�:  O(1)
	*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (k <= 0 || !pListHead)
			return nullptr;
		int n = 0;
		ListNode* p = pListHead;
		while (p)
		{
			p = p->next;
			n++;
		}
		if (n < k)
			return nullptr;
		n = n - k;
		while (n)
		{
			pListHead = pListHead->next;
			n--;
		}
		return pListHead;
	}
};

//2.�ϸ��O(n)�ⷨ������ָ��
	/*
		���� ����Ϊ   1->2->3->4->5->6->nullptr   �������������(4)
		��ͼ��֪ ������3�����Ϳս��֮����3��ָ��(��3��next)
		��������ָ��  ��һ��ָ��ָ������3�����  �ڶ���ָ��ָ��ս�� ���3
		����ƽ��  ����һ��ָ��ָ���һ�����   �ڶ���ָ��ָ��+3����� 
		�ȵڶ���ָ��ָ��ս��  ��һ��ָ����ָ������3�����

		ʱ�临�Ӷ�: O(n) ������� ��ֻ����һ�ε�����
		�ռ临�Ӷ�: O(1)
	*/

class Solution2 {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (!pListHead || k <= 0)
			return nullptr;
		ListNode* first = pListHead;
		ListNode* last = pListHead;
		while (k--)
		{
			if (last)
				last = last->next;
			else
				return nullptr;        //��������С��k   ֱ�ӷ���
		}
		while (last)
		{
			first = first->next;
			last = last->next;
		}
		return first;

	}
};
//int main()
//{
//	ListNode a(1);
//	ListNode b(2);
//	ListNode c(3);
//	ListNode d(4);
//	ListNode e(5);
//	a.next = &b;
//	b.next = &c;
//	c.next = &d;
//	d.next = &e;
//	e.next = NULL;
//
//	Solution s;
//	ListNode* p = s.FindKthToTail(&a, 1);
//	cout << p->val << endl;
//	return 0;
//}