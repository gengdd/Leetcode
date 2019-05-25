#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


//递归不对，可以从头循环
//class Solution {
//public:
//    string countAndSay(int n) {
//        if (n==1)
//            return "1";
//        else{
//            string t="";
//            string s=countAndSay(n-1);
//            int low=0,cur=0,sum=0;
//            while (cur<s.size()){
//                if (s[low]==s[cur]){
//                    cur+=1;
//                    sum+=1;
//                } else{
//                    int p=cur-low;
//                    char w= static_cast<char > (p);
//                    t=t+w;
//                    t=t+s[low];
//                    low=cur;
//                }
//            }
//            if (sum==s.size()){
//                char w= static_cast<char> (sum);
//                t=t+w;
//                t=t+s[0];
//            }
//            return t;
//        }
//    }
//};


//迭代法
//class Solution {
//public:
//    string countAndSay(int n) {
//        if (n==1)
//            return "1";
//        string res="1";
//        string res_cur="";
//        while (n!=1){
//            int low=0,cur=0,sum=0;
//            while (cur<res.size()){
//                if (res[low]==res[cur]){
//                    cur+=1;
//                    sum+=1;
//                } else{
//                    int p=cur-low;
//                    char w= static_cast<char>(p);
//                    res_cur=res_cur+w;
//                    res_cur=res_cur+res[low];
//                    low=cur;
//                }
//            }
//            if (sum==res.size()){
//                char w= static_cast<char> (sum);
//                res_cur=res_cur+w;
//                res_cur=res_cur+res[0];
//            }
//            res=res_cur;
//            n=n-1;
//        }
//        return res;
//    }
//};

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};













