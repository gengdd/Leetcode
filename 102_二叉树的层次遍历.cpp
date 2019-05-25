#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q{ {root} };
		while (!q.empty()) {
			vector<int> oneLevel;
			for (int i = q.size(); i > 0; --i) {
				TreeNode *t = q.front();
				q.pop();
				oneLevel.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(oneLevel);
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		levelorder(root, 0, res);
		return res;
	}
	void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
		if (!node) return;
		if (res.size() == level) res.push_back({});
		res[level].push_back(node->val);
		if (node->left) levelorder(node->left, level + 1, res);
		if (node->right) levelorder(node->right, level + 1, res);
	}
};