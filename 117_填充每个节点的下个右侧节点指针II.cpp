#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
		Node *p = root->next;
		while (p) {
			if (p->left) {
				p = p->left;
				break;
			}
			if (p->right) {
				p = p->right;
				break;
			}
			p = p->next;
		}
		if (root->right) root->right->next = p;
		if (root->left) root->left->next = root->right ? root->right : p;
		connect(root->right);
		connect(root->left);
		return root;
	}
};


class Solution {
public:
	Node* connect(Node* root) {
		Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
		while (root) {
			if (root->left) {
				cur->next = root->left;
				cur = cur->next;
			}
			if (root->right) {
				cur->next = root->right;
				cur = cur->next;
			}
			root = root->next;
			if (!root) {
				cur = dummy;
				root = dummy->next;
				dummy->next = NULL;
			}
		}
		return head;
	}
};

