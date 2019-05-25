#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//26进制转换
//class Solution {
//public:
//    string convertToTitle(int n) {
//        int y;
//        string s;
//        char t;
//        while (n!=0){
//            y=n%26;
//            n=n/26;
//            if (y==0){
//                t='Z';
//                n=n-1;
//            }
//            else
//                t=char(y-1+65);
//            s.push_back(t);
//        }
//        reverse(s.begin(),s.end());
//        return s;
//    }
//};

//代码简化
//class Solution {
//public:
//    string convertToTitle(int n) {
//        string res;
//        while (n){
//            res+=--n%26+'A';
//            n/=26;
//        }
//        return string(res.rbegin(),res.rend());
//    }
//};

//递归
class Solution {
public:
    string convertToTitle(int n) {
        return n==0?"":convertToTitle(n/26)+(char)(--n%26+'A');
    }
};






