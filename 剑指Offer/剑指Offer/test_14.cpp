#include<iostream>
#include<vector>

using namespace std;

/*
	题目描述:
		输入一个链表，输出该链表中倒数第k个结点
	示例:
		输入 1 2 3 4 5    输入  1
		输出   5
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//1.普通解法
	/*
		假设求倒数第K个结点，则正数应该从头结点往后推n-k个(n为总结点个数)
		例 总共有6个结点  求倒数第3个  (4) 
				1 2 3 4 5 6   则应该从头结点出发向后next3次
		还需要注意两个细节
			k<=0或者头结点最开始就为空
			结点的总个数<k
		时间复杂度:  O(2*n)  如果总是求倒数第一个结点，那么需要遍历两个链表
		空间复杂度:  O(1)
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

//2.严格的O(n)解法，快慢指针
	/*
		例： 链表为   1->2->3->4->5->6->nullptr   求倒数第三个结点(4)
		由图可知 倒数第3个结点和空结点之间有3个指针(即3次next)
		设有两个指针  第一个指针指向倒数第3个结点  第二个指针指向空结点 间隔3
		向左平移  即第一个指针指向第一个结点   第二个指针指向+3个结点 
		等第二个指针指向空结点  第一个指针则指向倒数第3个结点

		时间复杂度: O(n) 不管如何 都只遍历一次单链表
		空间复杂度: O(1)
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
				return nullptr;        //单链表长度小于k   直接返回
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