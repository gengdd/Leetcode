#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//错误
//求左子树和右子树的最大高度，比较
//class Solution {
//public:
//    bool isBalanced(TreeNode* root) {
//        if (!root)
//            return true;
//        int rmax = 0, lmax = 0;
//        queue<TreeNode *> ql, qr;
//        if (root->left != NULL) {
//            ql.push(root->left);
//            while (!ql.empty()) {
//                ++lmax;
//                for (int i = ql.size(); i > 0; --i) {
//                    TreeNode *t = ql.front();
//                    ql.pop();
//                    if (t->left)
//                        ql.push(t->left);
//                    if (t->right)
//                        ql.push(t->right);
//                }
//            }
//        } else{
//            rmax=0;
//        }
//        if (root->right!=NULL){
//            qr.push(root->right);
//            while (!qr.empty()) {
//                ++rmax;
//                for (int i = qr.size(); i > 0; --i) {
//                    TreeNode *t = qr.front();
//                    qr.pop();
//                    if (t->left)
//                        qr.push(t->left);
//                    if (t->right)
//                        qr.push(t->right);
//                }
//            }
//        } else{
//            lmax=0;
//        }
//        if (abs(lmax - rmax) <= 1)
//            return true;
//        else
//            return false;
//    }
//};

//class Solution {
//public:
//    bool isBalanced(TreeNode* root) {
//        if (!root)
//            return true;
//        if (abs(getDepth(root->left)-getDepth(root->right))>1)
//            return false;
//        return isBalanced(root->right)&&isBalanced(root->left);
//    }
//    int getDepth(TreeNode *root){
//        if (!root)
//            return 0;
//        return 1+max(getDepth(root->left),getDepth(root->right));
//    }
//};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (checkDepth(root)==-1)
            return false;
        else
            return true;
    }
    int checkDepth(TreeNode *root){
        if (!root)
            return 0;
        int left=checkDepth(root->left);
        if (left==-1)
            return -1;
        int right=checkDepth(root->right);
        if (right==-1)
            return -1;
        int diff=abs(left-right);
        if (diff>1)
            return -1;
        else
            return 1+max(left,right);
    }
};













