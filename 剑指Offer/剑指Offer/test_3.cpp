#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		����һ�������������β��ͷ��˳�򷵻�һ��ArrayList
	ʾ��:
		����   67 0 24 58
		���   58 24 0 67
*/

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};

//1.ʹ��std::reverse()����
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> temp;
		while (head!= NULL)
		{
			temp.push_back(head->val);
			head = head->next;
		}
		std::reverse(temp.begin(), temp.end());
		return temp;
	}
};

//2.�ݹ�
class Solution2 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> temp;
		if (head == NULL)
			return temp;
		temp = printListFromTailToHead(head->next);
		temp.push_back(head->val);
		return temp;
	}
};

//3.��ת����
class Solution3 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* temp = cur;
		while (cur)
		{
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		vector<int> ret;
		while (pre)
		{
			ret.push_back(pre->val);
			pre = pre->next;
		}
		return ret;
	}
};

//int main()
//{
//	/*ListNode a(67);
//	ListNode b(0);
//	ListNode c(24);
//	ListNode d(58);
//	a.next = &b;
//	b.next = &c;
//	c.next = &d;
//	d.next = NULL;
//
//	Solution s;
//	vector<int> vec = s.printListFromTailToHead(&a);
//	for (int i : vec)
//		cout << i << " ";
//	cout << endl;*/
//	return 0;
//}