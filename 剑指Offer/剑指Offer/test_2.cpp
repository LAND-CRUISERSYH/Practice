#include<iostream>
#include<string>

using namespace std;

/*
	题目描述:
		请实现一个函数，将一个字符串中的每个空格替换成"%20"
	例如:
		当字符串为We Are Happy时，则经替换之后的字符串为We%20Are%20Happy
*/

//1.先转为string，然后处理完成后再转为char*,用strcpy实现
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;
		string temp = str;
		string res;
		for (char x : temp)
		{
			if (x == ' ')
				res += "%20";
			else
				res += x;
		}
		strcpy(str, res.c_str());
	}
};

//2 从右向左遍历字符串 遇到空格填充%20 
	//首先得判断 有几个空格  重新给字符串一个长度 例如有三个空格 则new_length = length+3*2；
	//依次从右向左遍历  如果不是空格则复制，如果是空格则填充
class Solution2 {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;
		int n = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				n++;
		}
		if (n == 0)
			return;
		int new_length = length + n * 2;
		for (int i = length; i >= 0; i--)
		{
			if (str[i] != ' ')
				str[new_length--] = str[i];
			else
			{
				str[new_length--] = '0';
				str[new_length--] = '2';
				str[new_length--] = '%';
			}
		}
	}
};

//int main()
//{
//	/*Solution s;
//	char str[50] = "We Are Happy";
//	s.replaceSpace(str, strlen(str));
//	cout << str << endl;*/
//
//	/*Solution2 s;
//	char str[50] = "We Are Happy";
//	s.replaceSpace(str, strlen(str));
//	cout << str << endl;*/
//	return 0;
//}