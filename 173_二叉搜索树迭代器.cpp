#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *n = s.top();
		s.pop();
		int res = n->val;
		if (n->right) {
			n = n->right;
			while (n) {
				s.push(n);
				n = n->left;
			}
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}
private:
	stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */