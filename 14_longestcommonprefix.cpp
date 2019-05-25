#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//注意空字符串的情况
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string s;
//        if (strs.size()==0){
//            return "";
//        }
//        for (int i=0;i<strs[0].size();i++){
//            char t=strs[0][i];
//            int num=0;
//            for (int j=1;j<strs.size();j++){
//                if (strs[j][i]==t){
//                    num+=1;
//                }
//            }
//            //做计数器
//            if (num==strs.size()-1){
//                s.push_back(t);
//            } else{
//                break;
//            }
//        }
//        if (s.length()==0){
//            return "";
//        } else{
//            return s;
//        }
//    }
//};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0||strs[0]=="")
            return "";
        for (int i=0;i<strs[0].length();i++){
            char temp=strs[0][i];
            for (int j=1;j<strs.size();j++){
                if (i==strs[j].length()||strs[j][i]!=temp)
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};



//int main(){
//    vector<string> strs;
//    strs.push_back("flow");
//    strs.push_back("flower");
//    for (int i=0;i<strs.size();i++){
//        cout<<strs[i].size();
//        cout<<strs[i][0]<<endl;
//    }
//    return 0;
//}













