#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//遍历
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        ListNode *cur=head;
//        while (cur && cur->next){
//            if (cur->val==cur->next->val){
//                cur->next=cur->next->next;
//            } else{
//                cur=cur->next;
//            }
//        }
//        return head;
//    }
//};


//递归(不懂)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next)
            return head;
        head->next=deleteDuplicates(head->next);
        return (head->val==head->next->val)?head->next:head;
    }
};