#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//超出时间限制
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        for (int i=0;i<k;i++){
//            int s=nums[nums.size()-1];
//            for (int j=nums.size()-1;j>0;j--){
//                nums[j]=nums[j-1];
//            }
//            nums[0]=s;
//        }
//    }
//};

//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        vector<int> s;
//        for (int i=nums.size()-k;i<nums.size();i++){
//            s.push_back(nums[i]);
//        }
//        for (int i=nums.size()-1;i>=k;i++){
//            nums[i]=nums[i-k-1];
//        }
//        for (int i=0;i<k;i++){
//            nums[i]=s[i];
//        }
//    }
//};

//复制一个和nums一样的数组，
// 然后利用映射关系i -> (i+k)%n来交换数字
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        vector<int> t=nums;
//        for (int i=0;i<nums.size();++i){
//            nums[(i+k)%nums.size()]=t[i];
//        }
//    }
//};

//思路是先把前n-k个数字翻转一下，
// 再把后k个数字翻转一下，
// 最后再把整个数组翻转一下
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        if (nums.empty()||(k%=nums.size())==0)
//            return;
//        int n=nums.size();
//        reverse(nums.begin(),nums.begin()+n-k);
//        reverse(nums.begin()+n-k,nums.end());
//        reverse(nums.begin(),nums.end());
//    }
//};

//旋转数组的操作也可以看做从数组的末尾取k个数组放入数组的开头
//们用STL的push_back和erase可以很容易的实现这些操作
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        if (nums.empty() || (k %= nums.size()) == 0) return;
//        int n = nums.size();
//        for (int i = 0; i < n - k; ++i) {
//            nums.push_back(nums[0]);
//            nums.erase(nums.begin());
//        }
//    }
//};




