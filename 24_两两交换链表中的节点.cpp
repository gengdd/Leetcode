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
	ListNode* swapPairs(ListNode* head) {
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		while (pre->next&&pre->next->next) {
			ListNode *t = pre->next->next;
			pre->next->next = t->next;
			t->next = pre->next;
			pre->next = t;
			pre = t->next;
		}
		return dummy->next;
	}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *current = dummy;
		while (current->next != NULL && current->next->next != NULL) {
			swap2(current);
			current = current->next->next;
		}
		return dummy->next;
	}
	void swap2(ListNode *pre) {
		ListNode *dummy = pre->next;
		pre->next = dummy->next;
		dummy->next = dummy->next->next;
		pre->next->next = dummy;
	}
};



class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)return head;
		ListNode *t = head->next;
		head->next = swapPairs(head->next->next);
		t->next = head;
		return t;
	}
};