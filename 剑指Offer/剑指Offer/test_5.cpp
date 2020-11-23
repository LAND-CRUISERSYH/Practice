#include<iostream>
#include<stack>

using namespace std;

/*
	题目描述:
		用两个栈来实现一个队列，完成队列的Push和Pop操作。
		队列中的元素为int类型
*/


//    push操作直接往stack1中push
//    pop操作需要分情况:
		//如果stack2为空   需要将stack1中的数据转移到stack2中   然后对stack2进行pop
		//如果stack2不为空   直接pop就可以
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};