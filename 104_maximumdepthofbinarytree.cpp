#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
    int vat;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};


//层次遍历
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        int max=0;
//        if (!root)
//            return max;
//        queue<TreeNode*> q;
//        q.push(root);
//        while (!q.empty()){
//            ++max;
//            for (int i=q.size();i>0;--i){
//                TreeNode *t=q.front();
//                q.pop();
//                if (t->left)
//                    q.push(t->left);
//                if (t->right)
//                    q.push(t->right);
//            }
//        }
//        return max;
//    }
//};

//递归//深度优先DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};







