#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return NULL;
		int n = 0;
		ListNode *cur = head;
		while (cur) {
			++n;
			cur = cur->next;
		}
		k %= n;
		ListNode *fast = head, *slow = head;
		for (int i = 0; i < k; ++i) {
			if (fast)
				fast = fast->next;
		}
		if (!fast) return head;
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head;
		fast = slow->next;
		slow->next = NULL;
		return fast;
	}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return NULL;
		int n = 1;
		ListNode *cur = head;
		while (cur->next) {
			++n;
			cur = cur->next;
		}
		cur->next = head;
		int m = n - k % n;
		for (int i = 0; i < m; ++i) {
			cur = cur->next;
		}
		ListNode *newhead = cur->next;
		cur->next = NULL;
		return newhead;
	}
};

