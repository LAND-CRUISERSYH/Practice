#include<iostream>
#include<string>

using namespace std;

/*
	��Ŀ����:
		��ʵ��һ����������һ���ַ����е�ÿ���ո��滻��"%20"
	����:
		���ַ���ΪWe Are Happyʱ�����滻֮����ַ���ΪWe%20Are%20Happy
*/

//1.��תΪstring��Ȼ������ɺ���תΪchar*,��strcpyʵ��
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

//2 ������������ַ��� �����ո����%20 
	//���ȵ��ж� �м����ո�  ���¸��ַ���һ������ �����������ո� ��new_length = length+3*2��
	//���δ����������  ������ǿո����ƣ�����ǿո������
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