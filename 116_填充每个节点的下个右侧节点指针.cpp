#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (!root) return NULL;
		if (root->left) root->left->next = root->right;
		if (root->right) root->right->next = root->next ? root->next->left : NULL;
		connect(root->left);
		connect(root->right);
		return root;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (!root) return NULL;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				Node *t = q.front();
				q.pop();
				if (i < size - 1) {
					t->next = q.front();
				}
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return root;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (!root) return NULL;
		Node *start = root, *cur = NULL;
		while (start->left) {
			cur = start;
			while (cur) {
				cur->left->next = cur->right;
				if (cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			start = start->left;
		}
		return root;
	}
};
