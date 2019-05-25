#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//考虑情况少
//class Solution {
//public:
//    int minDepth(TreeNode* root) {
//        if (!root)
//            return 0;
//        return 1+min(minDepth(root->left),minDepth(root->right));
//    }
//};

//class Solution {
//public:
//    int minDepth(TreeNode* root) {
//        if (root){
//            if (root->right!=NULL && root->left==NULL)
//                return 1+minDepth(root->right);
//            if (root->left!=NULL && root->right==NULL)
//                return 1+minDepth(root->left);
//            if (root->left!=NULL && root->right!=NULL)
//                return 1+min(minDepth(root->left),minDepth(root->right));
//            else
//                return 1;
//        } else
//            return 0;
//    }
//};

迭代法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int res=0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            ++res;
            for (int i=q.size();i>0;--i){
                auto t=q.front();
                q.pop();
                if (!t->left && !t->right) //层次遍历求最小深度的关键
                    return res;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return -1;
    }
};
























