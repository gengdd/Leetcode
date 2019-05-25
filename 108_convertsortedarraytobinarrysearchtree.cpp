#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//所谓二叉搜索树，是一种始终满足左<根<右的特性
//将二叉搜索树按中序遍历的话，得到的就是一个有序数组了

//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        return helper(nums,0,(int)nums.size()-1);
//    }
//    TreeNode* helper(vector<int>& nums, int left, int right){
//        if (left>right)
//            return NULL;
//        int mid=left+(right-left)/2;
//        TreeNode *cur=new TreeNode(nums[mid]);
//        cur->left=helper(nums,left,mid-1);
//        cur->right=helper(nums,mid+1,right);
//        return cur;
//    }
//};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        int mid=nums.size()/2;
        TreeNode *cur=new TreeNode(nums[mid]);
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        cur->left=sortedArrayToBST(left);
        cur->right=sortedArrayToBST(right);
        return cur;
    }
};
















