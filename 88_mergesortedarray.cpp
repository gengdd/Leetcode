#include <iostream>
#include <vector>

using namespace std;


//错误
//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        vector<int> num;
//        for (int i=0;i<m;i++){
//            for (int j=0;j<n;j++){
//                if (nums1[i]<=nums2[j]){
//                    num.push_back(nums1[i]);
//                } else{
//                    num.push_back(nums2[j]);
//                }
//            }
//        }
//        for (int i=0;i<num.size();i++){
//            nums1[i]=num[i];
//        }
//    }
//};

//超时
//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int num=0;
//        for (int i=0;i<n;i++){
//            int x=0;
//            for(int j=num;j<m+i;j++){
//                if (nums1[j]<=nums2[i] && nums1[j+1]>nums2[i]){
//                    num=j;
//                    x+=1;
//                    break;
//                }
//            }
//            if (x==0){
//                for (int j=m+i+1;j<m+n;i++){
//                    nums1[j]=nums2[j-n];
//                }
//            } else{
//                for (int j=m+i;j>num+1;j--){
//                    nums1[j]=nums1[j-1];
//                }
//                nums1[num+1]=nums2[i];
//            }
//        }
//    }
//};



//不从头遍历，从尾部遍历，将数值较大的放在nums1最末尾，依次比较。
//从头遍历需要依次将大于的值后移
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while (i>=0 && j>=0){
            if (nums1[i]>nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        while (j>=0)
            nums1[k--]=nums2[j--];
    }
};
























