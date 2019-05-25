#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		unordered_map<Node*, Node*>m;
		return helper(node, m);
	}
	Node* helper(Node* node, unordered_map<Node*, Node*>&m) {
		if (!node) return NULL;
		if (m.count(node)) return m[node];
		Node *clone = new Node(node->val);
		m[node] = clone;
		for (Node *neighbors : node->neighbors) {
			clone->neighbors.push_back(helper(neighbors, m));
		}
		return clone;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return NULL;
		unordered_map<Node*, Node*>m;
		queue<Node*> q{ {node} };
		Node *clone = new Node(node->val);
		m[node] = clone;
		while (!q.empty()) {
			Node *t = q.front();
			q.pop();
			for (Node *neighbor : t->neighbors) {
				if (!m.count(neighbor)) {
					m[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}
				m[t]->neighbors.push_back(m[neighbor]);
			}
		}
		return clone;
	}
};

