#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return nullptr;
		Node *res = new Node(head->val, nullptr, nullptr);
		Node *node = res, *cur = head->next;
		unordered_map<Node*, Node*> m;
		m[head] = res;
		while (cur) {
			Node *t = new Node(cur->val, nullptr, nullptr);
			node->next = t;
			m[cur] = t;
			node = node->next;
			cur = cur->next;
		}
		node = res;
		cur = head;
		while (cur) {
			node->random = m[cur->random];
			node = node->next;
			cur = cur->next;
		}
		return res;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return nullptr;
		Node *cur = head;
		while (cur) {
			Node *t = new Node(cur->val, nullptr, nullptr);
			t->next = cur->next;
			cur->next = t;
			cur = t->next;
		}
		cur = head;
		while (cur) {
			if (cur->random) cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		cur = head;
		Node *res = head->next;
		while (cur) {
			Node *t = cur->next;
			cur->next = t->next;
			if (t->next) t->next = t->next->next;
			cur = cur->next;
		}
		return res;
	}
};