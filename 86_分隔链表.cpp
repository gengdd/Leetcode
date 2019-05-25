#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy, *cur = head;
		while (pre->next && pre->next->val < x) pre = pre->next;
		cur = pre;
		while (cur->next) {
			if (cur->next->val < x) {
				ListNode *tmp = cur->next;
				cur->next = tmp->next;
				tmp->next = pre->next;
				pre->next = tmp;
				pre = pre->next;
			}
			else {
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *newDummy = new ListNode(-1);
		dummy->next = head;
		ListNode *cur = dummy, *p = newDummy;
		while (cur->next) {
			if (cur->next->val < x) {
				p->next = cur->next;
				p = p->next;
				cur->next = cur->next->next;
				p->next = NULL;
			}
			else {
				cur = cur->next;
			}
		}
		p->next = dummy->next;
		return newDummy->next;
	}
};