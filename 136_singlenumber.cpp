#include <iostream>
#include <vector>

using namespace std;

//错误
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int cur=1,low=0;
//        while (cur<nums.size()){
//            if (nums[cur]!=nums[low]){
//                cur=cur+1;
//            }
//            if (nums[cur]==nums[low]){
//                swap(nums[cur],nums[low+1]);
//                low=low+2;
//                cur=low+1;
//            }
//        }
//        return nums[low];
//    }
//};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (auto num:nums)
            res^=num;
        return res;
    }
};


