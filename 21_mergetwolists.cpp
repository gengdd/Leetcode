#include <iostream>
using namespace std;


//链表
struct ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){
    }
};

//迭代解法，考虑长短不一。
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        ListNode *dummy=new ListNode(-1);
//        ListNode *cur=dummy;
//        while (l1 && l2){
//            if (l1->val<l2->val){
//                cur->next=l1;
//                l1=l1->next;
//            } else{
//                cur->next=l2;
//                l2=l2->next;
//            }
//            cur=cur->next;
//        }
//        cur->next=l1?l1:l2;
//        return dummy->next;
//    }
//};

//递归法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        } else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};





