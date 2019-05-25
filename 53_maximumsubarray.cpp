#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//暴力遍历,超出内存限制
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        vector<int> t;
//        int s;
//        for (int i=0;i<nums.size();i++){
//            s=nums[i];
//            t.push_back(s);
//            for (int j=i+1;j<nums.size();j++){
//                s=s+nums[j];
//                t.push_back(s);
//            }
//        }
//        int max=t[0];
//        for (int i=0;i<t.size();i++){
//            if (t[i]>max){
//                max=t[i];
//            }
//        }
//        return max;
//    }
//};


//O(n)
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int res=INT_MIN,curSum=0;
//        for (int num:nums){
//            curSum=max(curSum+num,num);
//            res=max(res,curSum);
//        }
//        return res;
//    }
//};

//O(nlogn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        return helper(nums,0,(int)nums.size()-1);
    }
    int helper(vector<int>&nums,int left,int right){
        if (left>=right)
            return nums[left];
        int mid=left+(right-left)/2;
        int lmax=helper(nums,left,mid-1);
        int rmax=helper(nums,mid+1,right);
        int mmax=nums[mid];
        int t=mmax;
        for (int i=mid-1;i<left;--i){
            t+=nums[i];
            mmax=max(mmax,t);
        }
        t=mmax;
        for (int i=mid+1;i<=right;++i){
            t+=nums[i];
            mmax=max(mmax,t);
        }
        return max(mmax,max(lmax,rmax));
    }
};



























