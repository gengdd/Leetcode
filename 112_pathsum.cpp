#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//错误
//class Solution {
//public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        vector<int> s;
//        int num=0;
//        while (root!=NULL){
//            num+=root->val;
//            if (root->left!=NULL){
//                num+=root->left;
//                root=root->left;
//                continue;
//            }
//            if (root->right!=NULL){
//                num+=root->right;
//                root=root->right;
//                continue;
//            }
//            if (root->left==NULL && root->right==NULL){
//                s.push_back(num);
//                break;
//            }
//        }
//
//    }
//};


//深度优先算法DFS的思想来遍历每一条完整的路径
//class Solution {
//public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        if (!root)
//            return false;
//        if (!root->left && !root->right && root->val==sum)
//            return true;
//        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
//    }
//};

//迭代法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()){
            TreeNode *t=st.top();
            st.pop();
            if (!t->left && !t->right){
                if (t->val==sum)
                    return true;
            }
            if (t->right){
                t->right->val+=t->val;
                st.push(t->right);
            }
            if (t->left){
                t->left->val+=t->val;
                st.push(t->left);
            }
        }
        return false;
    }
};
































