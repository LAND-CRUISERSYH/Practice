#include<iostream>
#include<stack>

using namespace std;

/*
	��Ŀ����:
		������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������
		�����е�Ԫ��Ϊint����
*/


//    push����ֱ����stack1��push
//    pop������Ҫ�����:
		//���stack2Ϊ��   ��Ҫ��stack1�е�����ת�Ƶ�stack2��   Ȼ���stack2����pop
		//���stack2��Ϊ��   ֱ��pop�Ϳ���
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