#include <iostream>
#include <stack>
#include <queue>

using namespace std;
//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//仿写类似100
//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        stack<TreeNode*> s1,s2;
//        if (root){
//            s1.push(root);
//            s2.push(root);
//        }
//        while (!s1.empty() && !s2.empty()){
//            TreeNode *t1=s1.top();
//            s1.pop();
//            TreeNode *t2=s2.top();
//            s2.pop();
//            if (t1->val!=t2->val)
//                return false;
//            if (t1->left)
//                s1.push(t1->left);
//            if (t2->right)
//                s2.push(t2->right);
//            if (s1.size()!=s2.size())
//                return false;
//            if (t1->right)
//                s1.push(t1->right);
//            if (t2->left)
//                s2.push(t2->left);
//            if (s1.size()!=s2.size())
//                return false;
//        }
//        return s1.size()==s2.size();
//    }
//};


//递归
//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        if (!root)
//            return true;
//        return isSymmetric(root->left,root->right);
//    }
//    bool isSymmetric(TreeNode *left, TreeNode *right){
//        if  (!left && !right)
//            return true;
//        if (left && !right || !left && right || left->val!=right->val)
//            return false;
//        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
//    }
//};

//迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty()&&!q2.empty()){
            TreeNode *node1=q1.front();
            q1.pop();
            TreeNode *node2=q2.front();
            q2.pop();
            if (!node1 && !node2)
                continue;
            if ((node1&& !node2) || (!node1 && node2))
                return false;
            if (node1->val!=node2->val)
                return false;
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }
        return true;
    }
};




























