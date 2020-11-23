#include<iostream>
#include<vector>

using namespace std;

/*
	��Ŀ����:
		����ĳ��������ǰ�������������������ؽ����ö�������
		���������ǰ���������������Ľ���������ظ������֡�
		��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6},���ؽ�������������
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	TreeNode* rebulid(vector<int>& pre, int pre_left, int pre_right, vector<int>& vin, int vin_left, int vin_right)
	{
		if (pre_left > pre_right)
			return nullptr;
		TreeNode* root = new TreeNode(pre[pre_left]);
		for (int i = vin_left; i <= vin_right; i++)
		{
			if (vin[i] == root->val)
			{
				root->left = rebulid(pre, pre_left + 1, pre_left + i - vin_left, vin, vin_left, i - 1);
				root->right = rebulid(pre, pre_left + i - vin_left + 1, pre_right, vin, i + 1, vin_right);
				break;
			}
		}
		return root;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return rebulid(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
};