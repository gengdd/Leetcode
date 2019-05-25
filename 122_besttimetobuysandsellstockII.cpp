#include <iostream>
#include <vector>

using namespace std;


//如果当前价格比之前价格高，则把差值加入利润中，因为我们可以昨天买入，今日卖出，
// 若明日价更高的话，还可以今日买入，明日再抛出。以此类推，遍历完整个数组后即可求得最大利润。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for (int i=1;i<prices.size();i++){
            if (prices[i]>prices[i-1])
                res+=prices[i]-prices[i-1];
        }
        return res;
    }
};











