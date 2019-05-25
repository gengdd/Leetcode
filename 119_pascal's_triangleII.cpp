#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> getRow(int rowIndex) {
//        vector<int> t;
//        vector<int> s;
//        t.resize(rowIndex+1,1);
//        s.resize(rowIndex+1,1);
//        for (int i=0;i<rowIndex-1;++i){
//            for (int j=1;j<i+2;++j){
//                t[j]=s[j-1]+s[j];
//            }
//            s=t;
//        }
//        return t;
//    }
//};

//注意杨辉三角的性质
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0]=1;
        for(int i=1;i<=rowIndex;++i){
            for (int j=i;j>=1;--j){
                res[j]+=res[j-1];
            }
        }
        return res;
    }
};





