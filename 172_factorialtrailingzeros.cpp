#include <iostream>

using namespace std;

//错误，情况少了
//class Solution {
//public:
//    int trailingZeroes(int n) {
//        int x,y;
//        int s=0,t=0;
//        x=n/10;
//        y=n%10;
//        if (y>=5)
//            s=x+1;
//        else
//            s=x;
//        return x+s;
//    }
//};

//找出5的个数
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while (n){
            res=res+n/5;
            n/=5;
        }
        return res;
    }
};



