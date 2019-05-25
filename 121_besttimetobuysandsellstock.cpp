#include <iostream>
#include <vector>

using namespace std;


//超时
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<int> s;
//        int w;
//        for (int i=0;i<prices.size();i++){
//            for (int j=i+1;j<prices.size();j++){
//                w=prices[j]-prices[i];
//                s.push_back(w);
//            }
//        }
//        int max=s[0];
//        for (int i=0;i<s.size();i++){
//            if (s[i]>=max){
//                max=s[i];
//            }
//        }
//        if (max<=0)
//            return 0;
//        else
//            return max;
//    }
//};

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int min,max;
//        min=prices[0];
//        max=0;
//        for (int i=0;i<prices.size();i++){
//            if (prices[i]<=min){
//                min=prices[i];
//            }
//            if (prices[i]-min>max){
//                max=prices[i]-min;
//            }
//        }
//        return max;
//    }
//};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0,buy=INT_MAX;
        for (int price:prices){
            buy=min(buy,price);
            res=max(res,price-buy);
        }
        return res;
    }
};



























