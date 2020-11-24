#include<iostream>

using namespace std;

/*
	题目描述:
		输入一个链表  反转链表后   输出新链表的表头
	示例:
		输入 123          返回值 321
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
/*
	初始化3个指针:
		pre指针指向正在反转的前一个结点(已经反转好的最后一个结点)，最开始反转表头，(表头反转即为表尾)，所以pre指向nullptr
		cur指针指向正在反转的结点，最开始反转表头，所以指向表头
		temp指针指向下一个待反转的结点，目的是保存结点防止断开，因为cur改变指向后，后面的链表需要保存
	操作:
		temp = cur->next;     保存未反转的链表
		cur->next = pre;      正在反转cur指向，指向已经反转好的最后一个结点
		pre = cur;          指针后移，去操作下一个待反转的结点，即之前temp保存的结点
		cur = temp;
	循环结束后，cur为nullptr(也为循环结束的条件)，函数返回pre指针，指向的是反转后的头结点，即cur的前一个结点
	时间复杂度:O(n)   遍历一次链表
	空间复杂度:O(1)
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