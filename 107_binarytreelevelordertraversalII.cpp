#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};


//层次遍历//广度优先搜索BFS
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        if (!root)
//            return {};
//        vector<vector<int>> res;
//        queue<TreeNode*> q;
//        q.push(root);
//        while (!q.empty()){
//            vector<int> oneLevel;
//            for (int i=q.size();i>0;--i){
//                TreeNode *t=q.front();
//                q.pop();
//                oneLevel.push_back(t->val);
//                if (t->left)
//                    q.push(t->left);
//                if (t->right)
//                    q.push(t->right);
//            }
//            res.insert(res.begin(),oneLevel);
//        }
//        return res;
//    }
//};


//由于递归的特性，我们会一直深度优先去处理左子结点
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root,0,res);
        return vector<vector<int>> (res.rbegin(),res.rend());
    }
    void levelorder(TreeNode* node,int level, vector<vector<int>>& res){
        if (!node)
            return ;
        if (res.size()==level)
            res.push_back({});
        res[level].push_back(node->val);
        if (node->left)
            levelorder(node->left,level+1,res);
        if (node->right)
            levelorder(node->right,level+1,res);
    }
};






