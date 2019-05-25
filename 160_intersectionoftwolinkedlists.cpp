#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//超出时间限制，写错进入死循环
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        ListNode *a=headA;
//        ListNode *b=headB;
//        int x=0,y=0;
//        while (a!=NULL)
//            x=x+1; //这里写错了
//        while (b!=NULL)
//            y=y+1; //这里写错了
//        if (x<y){
//            for (int i=0;i<y-x;i++){
//                headB=headB->next;
//            }
//        } else{
//            for (int i=0;i<x-y;i++){
//                headA=headA->next;
//            }
//        }
//        while (headA!=NULL && headB!=NULL){
//            if (headA->val==headB->val)
//                return headA;
//            headA=headA->next;
//            headB=headB->next;
//        }
//        return nullptr;
//    }
//};

//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        if (!headA||!headB)
//            return NULL;
//        int lenA=getLength(headA);
//        int lenB=getLength(headB);
//        if (lenA<lenB){
//            for (int i=0;i<lenB-lenA;++i)
//                headB=headB->next;
//        } else{
//            for (int i=0;i<lenA-lenB;++i)
//                headA=headA->next;
//        }
//        while (headA&&head&&headA!=headB){
//            headA=headA->next;
//            headB=headB->next;
//        }
//        return (headA&&headB)?headA:NULL;
//    }
//    int getLength(ListNode *head){
//        int cnt=0;
//        while (head){
//            ++cnt;
//            head=head->next;
//        }
//        return cnt;
//    }
//};

//虽然题目中强调了链表中不存在环，但是我们可以用环的思想来做，
// 我们让两条链表分别从各自的开头开始往后遍历，
// 当其中一条遍历到末尾时，我们跳到另一个条链表的开头继续遍历
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *a=headA,*b=headB;
        while (a!=b){
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        return a;
    }
};


























