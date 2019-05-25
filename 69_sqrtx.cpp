#include <iostream>
#include <math.h>
using namespace std;

//整数溢出

//蛮力算法注意整型溢出
//class Solution {
//public:
//    int mySqrt(int x) {
//        if (x>46340*46340)
//            return 46340;
//        for (int i=1;i<=x;i++){
//            if (i*i<x){
//                continue;
//            } else if (i*i==x){
//                return i;
//            } else if (i*i>x){
//                return i-1;
//            }
//        }
//        return 0;
//    }
//};

//二分搜索法
//class Solution {
//public:
//    int mySqrt(int x) {
//        if (x<=1)
//            return x;
//        int left=0,right=x;
//        while (left<right){
//            int mid=left+(right-left)/2;
//            if (x/mid>=mid)
//                left=mid+1;
//            else
//                right=mid;
//        }
//        return right-1;
//    }
//};

//牛顿迭代法
class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
            return 0;
        double res=1,pre=0;
        while (abs(res-pre)>1e-6){
            pre=res;
            res=(res+x/res)/2;
        }
        return int(res);
    }
};





