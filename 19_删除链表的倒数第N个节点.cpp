#include<ios>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		int len=0;
//		ListNode* s = head;
//		while (s != NULL) {
//			len += 1;
//			s = s->next;
//		}
//		for (int i = 0; i < len; i++) {
//			if (i == len - n) {
//				if (head->next->next != NULL) {
//					head = head->next->next;
//					continue;
//				}
//				else
//				{
//					head = NULL;
//					break;
//				}
//			}
//			else
//				head = head->next;
//		}
//		return head;
//	}
//};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head->next) return NULL;
		ListNode *pre = head, *cur = head;
		for (int i = 0; i < n; i++)
			cur = cur->next;
		if (!cur)
			return head->next;
		while (cur->next) {
			cur = cur->next;
			pre = pre->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};
