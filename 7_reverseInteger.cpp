#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//无溢出检查
//class Solution {
//public:
//    int reverse(int x) {
//        vector<int> s;
//        int y,sys;
//        int rev=0;
//        if (x>2147483647||x<-2147483648){
//            return 0;
//        }
//        if (x>0){
//            sys=0;
//        } else{
//            x=-x;
//            sys=1;
//        }
//        while (x!=0){
//            y=x%10;
//            x=x/10;
//            s.push_back(y);
//        }
//        for (int i=0;i<s.size();++i){
//            rev=10*rev+s[i];
//        }
//        if (sys==0){
//            return rev;
//        } else{
//            return -rev;
//        }
//    }
//};

//正确代码
class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while (x!=0){
            int pop=x%10;
            x=x/10;
            if (rev> INT_MAX/10||(rev==INT_MAX/10 && pop>7))
                return 0;
            if (rev<INT_MIN/10||(rev==INT_MIN/10 && pop<-8))
                return 0;
            rev=rev*10+pop;
        }
        return rev;
    }
};















