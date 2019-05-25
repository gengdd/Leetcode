#include <iostream>
using namespace std;

//直观版本，但是数字过大时栈的缓冲区溢出
//class Solution {
//public:
//    int romanToInt(string s) {
//        int sum=0;
//        string::iterator it;
//        for (it=s.begin();it!=s.end()-1;it++){
//            if (*it=='I'){
//                if (*it+1=='V'){
//                    sum=sum+4;
//                    s.erase(it);
//                    s.erase(it+1);
//                }
//                if (*it+1=='X'){
//                    sum=sum+9;
//                    s.erase(it);
//                    s.erase(it+1);
//                }
//            }
//            if (*it=='X'){
//                if (*it+1=='L'){
//                    sum=sum+40;
//                    s.erase(it);
//                    s.erase(it+1);
//                }
//                if (*it+1=='C'){
//                    sum=sum+90;
//                    s.erase(it);
//                    s.erase(it+1);
//                }
//            }
//            if (*it=='C'){
//                if (*it+1=='D'){
//                    sum=sum+400;
//                    s.erase(it);
//                    s.erase(it+1);
//                }
//                if (*it+1=='M'){
//                    sum=sum+900;
//                    s.erase(it);
//                    s.erase(it+1);
//                }
//            }
//        }
//        for (it=s.begin();it!=s.end();it++){
//            if (*it=='I'){
//                sum=sum+1;
//            }
//            if (*it=='V'){
//                sum=sum+5;
//            }
//            if (*it=='X'){
//                sum=sum+10;
//            }
//            if (*it=='L'){
//                sum=sum+50;
//            }
//            if (*it=='C'){
//                sum=sum+100;
//            }
//            if (*it=='D') {
//                sum = sum + 500;
//            }
//            if (*it=='M') {
//                sum = sum + 1000;
//            }
//        }
//        if (sum<1 || sum>3999){
//            return 0;
//        }
//        return sum;
//    }
//};

//swith语句使用，将字符串映射成一个数组，再将其计算。
//class Solution {
//public:
//    int romanToInt(string s) {
//        int sum[50]={0};
//        int num=0;
//        for (int i=0;i<s.size();i++){
//            switch (s[i]){
//                case 'I':sum[i]=1;
//                    break;
//                case 'V':sum[i]=5;
//                    break;
//                case 'X':sum[i]=10;
//                    break;
//                case 'L':sum[i]=50;
//                    break;
//                case 'C':sum[i]=100;
//                    break;
//                case 'D':sum[i]=500;
//                    break;
//                case 'M':sum[i]=1000;
//                    break;
//                default:sum[i]=0;
//            }
//            if (i>0&&sum[i]>sum[i-1]){
//                sum[i]=sum[i]-sum[i-1];
//            }
//        }
//        for (int i=0;i<s.size();i++){
//            num+=sum[i];
//        }
//        return num;
//    }
//};






































