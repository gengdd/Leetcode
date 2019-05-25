#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


//错误
//class Solution {
//public:
//    bool hasCycle(ListNode *head) {
//        ListNode *cur=head;
//        ListNode *low=head;
//        while (cur!=NULL ||low->next!=NULL || cur->next->next!=NULL){
//            cur=cur->next->next;
//            low=low->next;
//            if (low>cur){
//                return true;
//            }
//        }
//        return false;
//    }
//};

//快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while (fast && fast->next){  //终止条件
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                return true;
            }
        }
        return false;
    }
};


