#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        for (int i=0;i<nums.size();i++){
//            if (nums[i]==target){
//                return i;
//            }
//        }
//        if (nums[0]>target)
//            return 0;
//        if (nums[nums.size()]<target)
//            return nums.size()+1;
//        for (int i=1;i<nums.size();i++){
//            if (nums[i-1]<target && nums[i]>target)
//                return i;
//        }
//        return 0;
//    }
//};


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();i++){
            if (nums[i]>=target)
                return i;
        }
        return nums.size();
    }
};

