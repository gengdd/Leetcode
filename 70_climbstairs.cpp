#include <iostream>

using namespace std;

//背包问题

//暴力计算,错误，需要考虑排列组合
//class Solution {
//public:
//    int climbStairs(int n) {
//        int x,y;
//        x=n;
//        y=n/2;
//        int num=0;
//        for (int i=0;i<=x;i++){
//            for (int j=0;j<=y;j++){
//                if (i+2*y==n)
//                    num+=1;
//            }
//        }
//        return num;
//    }
//};

//递归，超时
//class Solution {
//public:
//    int climbStairs(int n) {
//        int sum;
//        if (n==1)
//            return 1;
//        if (n==2)
//            return 2;
//        if (n>=3){
//            sum=climbStairs(n-1)+climbStairs(n-2);
//        }
//        return sum;
//    }
//};

//动态规划..数组存储，逐个元素计算
class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
            return 1;
        else if (n==2)
            return 2;
        else {
            int dp[n + 1];
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    }
};








