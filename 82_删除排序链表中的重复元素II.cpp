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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		while (pre->next) {
			ListNode *cur = pre->next;
			while (cur->next!=NULL && cur->next->val == cur->val) {
				cur = cur->next;
			}
			if (cur != pre->next) pre->next = cur->next;
			else pre = pre->next;
		}
		return dummy->next;
	}
};


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		if (head->next && head->val == head->next->val) {
			while (head->next && head->val == head->next->val) {
				head = head->next;
			}
			return deleteDuplicates(head->next);
		}
		head->next = deleteDuplicates(head->next);
		return head;
	}
};
