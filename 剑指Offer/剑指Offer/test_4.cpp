#include<iostream>
#include<vector>

using namespace std;

/*
	题目描述:
		输入某二叉树的前序遍历和中序遍历，请重建出该二叉树。
		假设输入的前序遍历和中序遍历的结果都不含重复的数字。
		例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6},则重建二叉树并返回
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