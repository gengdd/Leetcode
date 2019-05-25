#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//暴力求解
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int sum;
//        vector<int> s;
//        for (int i=0;i<nums.size();i++){
//            for (int j=0;j<nums.size();j++){
//                if (i!=j){
//                    sum=nums[i]+nums[j];
//                    if (sum==target){
//                        s.push_back(i);
//                        s.push_back(j);
//                        break;
//                    }
//                }
//            }
//            if (s.size()!=0){
//                break;
//            }
//        }
//        return s;
//    }
//};

//哈希表实现
//map
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int,int> m;
//        for (int i=0;i<nums.size();++i) {
//            if (m.count(target - nums[i])){
//                return {i,m[target-nums[i]]};
//            }
//            m[nums[i]]=i;
//        }
//        return {};
//    }
//};

