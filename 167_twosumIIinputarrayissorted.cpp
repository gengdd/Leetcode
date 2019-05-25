#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        unordered_map<int,int> m;
//        for (int i=0;i<numbers.size();++i){
//            if (m.count(target-numbers[i])){
//                if (i<m[target-numbers[i]])
//                    return {i+1,m[target-numbers[i]]+1};
//                else
//                    return {m[target-numbers[i]]+1,i+1};
//            }
//            m[numbers[i]]=i;
//        }
//        return {};
//    }
//};

//注意有序这个条件，可以二分查找，可以两边向中间夹逼
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0,fast=numbers.size()-1;
        while (low<fast){
            if (numbers[low]+numbers[fast]>target){
                fast=fast-1;
            }
            if (numbers[low]+numbers[fast]<target){
                low=low+1;
            }
            if (numbers[low]+numbers[fast]==target){
                return {low+1,fast+1};
            }
        }
        return {};
    }
};














