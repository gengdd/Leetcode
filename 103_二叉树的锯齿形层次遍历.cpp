#include<iostream>
#include<vector>
#include<queue>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		s1.push(root);
		vector<int> out;
		while (!s1.empty() || !s2.empty()) {
			while (!s1.empty()) {
				TreeNode *cur = s1.top();
				s1.pop();
				out.push_back(cur->val);
				if (cur->left) s2.push(cur->left);
				if (cur->right) s2.push(cur->right);
			}
			if (!out.empty()) res.push_back(out);
			out.clear();
			while (!s2.empty()) {
				TreeNode *cur = s2.top();
				s2.pop();
				out.push_back(cur->val);
				if (cur->right) s1.push(cur->right);
				if (cur->left) s1.push(cur->left);
			}
			if (!out.empty()) res.push_back(out);
			out.clear();
		}
		return res;
	}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	if (!root)return {};
	vector<vector<int>> ans;
	queue<TreeNode *>que{ {root} };
	int count = 0;
	while (!que.empty()) {
		count++;
		vector<int>oneLevel;
		int n = que.size();
		for (int i = 0; i < n; i++) {
			TreeNode *t = que.front(); que.pop();
			oneLevel.push_back(t->val);
			if (t->left)que.push(t->left);
			if (t->right)que.push(t->right);
		}
		if (!(count & 0x1))reverse(oneLevel.rbegin(), oneLevel.rend());
		ans.push_back(oneLevel);
	}
	return ans;
}