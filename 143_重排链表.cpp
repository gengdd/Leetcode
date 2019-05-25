#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;
		ListNode *fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *mid = slow->next;
		slow->next = NULL;
		ListNode *last = mid, *pre = NULL;
		while (last) {
			ListNode *next = last->next;
			last->next = pre;
			pre = last;
			last = next;
		}
		while (head&&pre) {
			ListNode *next = head->next;
			head->next = pre;
			pre = pre->next;
			head->next->next = next;
			head = next;
		}
	}
};