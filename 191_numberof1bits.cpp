#include <iostream>

using namespace std;


//位运算，取最后一位
//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int count=0;
//        for (int i=0;i<32;i++){
//            if (n&1==1)
//                count=count+1;
//            n=n>>1;
//        }
//        return count;
//    }
//};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        for (;n;n=n&(n-1))
            ++res;
        return res;
    }
};











