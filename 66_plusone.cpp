#include <iostream>
#include <vector>
using namespace std;



//思路不对
//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        vector<int> x;
//        for (int i=0;i<digits.size();i++){
//            if (i==digits.size()-1){
//                if (digits[i]==9){
//                    x.push_back(1);
//                    x.push_back(0);
//                } else{
//                    x.push_back(digits[i]+1);
//                }
//            } else{
//                x.push_back(digits[i]);
//            }
//        }
//        return x;
//    }
//};

//先转换为数字，在转化为数组//整型溢出
//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        int sum=0;
//        vector<int> x;
//        for (int i=0;i<digits.size();i++){
//            sum=sum*10+digits[i];
//        }
//        sum=sum+1;
//        int y;
//        while (sum!=0){
//            y=sum%10;
//            sum=sum/10;
//            x.push_back(y);
//        }
//        vector<int> z;
//        for (int i=x.size()-1;i>=0;i--){
//            z.push_back(x[i]);
//        }
//        return z;
//    }
//};

//
//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        vector<int> x;
//        for (int i=0;i<digits.size();i++){
//            if (i!=digits.size()-1){
//                x.push_back(digits[i]);
//            } else{
//                if (digits[i]!=9){
//                    x.push_back(digits[i]+1);
//                } else{
//                    for (int j=digits.size()-1;j<=0;j--){
//                        if (x[j]==9) {
//                            x[j] = 0;
//                            if (j==0){
//                                x.insert(x.begin(),1);
//                            }
//                        } else{
//                            x[j]=x[j]+1;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//        return x;
//    }
//};


//从尾部遍历
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for (int i=n-1;i>=0;i--){
            if (digits[i]!=9){
                digits[i]=digits[i]+1;
                return digits;
            } else{
                digits[i]=0;
            }
        }
        if (digits.front()==0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};











































