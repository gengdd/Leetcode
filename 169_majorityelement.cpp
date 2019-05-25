#include <iostream>
#include <vector>
#include <map>

using namespace std;


//摩尔投票法
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int res=0,cnt=0;
//        for (int num:nums){
//            if (cnt==0){
//                res=num;
//                ++cnt;
//            } else{
//                num==res?++cnt:--cnt;
//            }
//        }
//        return res;
//    }
//};

//位操作Bit Manipulation来解
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int res=0,n=nums.size();
//        for (int i=0;i<32;++i){
//            int ones=0,zeros=0;
//            for (int num:nums){
//                if (ones>n/2||zeros>n/2) break;
//                if ((num&(1<<i))!=0) ++ones;
//                else ++zeros;
//            }
//            if (ones>zeros) res|=(1<<i);
//        }
//        return res;
//    }
//};

//map解法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> s;
        for (int i=0;i<nums.size();i++){
            int key=nums[i];
            if (s.find(key)==s.end()){
                s[key]=1;
            } else{
                s[key]=s[key]+1;
            }
            if (s[key]>nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};











