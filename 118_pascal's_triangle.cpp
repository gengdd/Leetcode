#include <iostream>
#include <vector>

using namespace std;


//错误
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> s;
//        if (numRows==1){
//            s[0][0]=1;
//        }
//        for (int i=1;i<numRows;i++){
//            vector<int> w;
//            w[0]=s[i-1][0];
//            for (int j=1;j<i;j++){
//                w[j]=s[i-1][j-1]+s[i-1][j];
//            }
//            w[i]=s[i-1][i];
//            s.push_back(w);
//        }
//        return s;
//    }
//};

//利用周边都是1，则可以不用计算。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());
        for (int i=0;i<numRows;i++){
            res[i].resize(i+1,1);
            for (int j=1;j<i;++j){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};










