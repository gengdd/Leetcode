#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		vector<int> vals;
		inorder(root, vals);
		for (int i = 0; i < vals.size() - 1; ++i) {
			if (vals[i] >= vals[i + 1]) return false;
		}
		return true;
	}
	void inorder(TreeNode* root, vector<int>& vals) {
		if (!root) return;
		inorder(root->left, vals);
		vals.push_back(root->val);
		inorder(root->right, vals);
	}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode *p = root, *pre = NULL;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			if (pre && p->val <= pre->val) return false;
			pre = p;
			p = p->right;
		}
		return true;
	}
};