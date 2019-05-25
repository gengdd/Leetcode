#include <iostream>
#include <string>
using namespace std;

//普通解法
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        int x,y;
//        x=haystack.length();
//        y=needle.length();
//        if (x<y)
//            return -1;
//        if (y==0)
//            return 0;
//        if (x==y) {
//            int sum = 0;
//            for (int i = 0; i < x; i++){
//                if (haystack[i] == needle[i])
//                    sum += 1;
//            }
//            if (sum==x){
//                return 0;
//            }
//        }
//        for (int i=0;i<x-y+1;i++){
//            int sum=0;
//            for (int j=0;j<y;j++){
//                if (haystack[i+j]==needle[j])
//                    sum+=1;
//                else
//                    break;
//            }
//            if (sum==y){
//                return i;
//            }
//        }
//        return -1;
//    }
//};

//利用字符串,利用一个字符串，初始化新字符串。
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty()||needle.size()>haystack.size())
            return -1;
        int sum_s=needle.size();
        for (int i{0};i<=haystack.size()-sum_s;i++){
            string tmp(haystack,i,sum_s);
            if (tmp==needle)
                return i;
        }
        return -1;
    }
};























