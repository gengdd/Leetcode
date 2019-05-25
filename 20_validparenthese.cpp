#include <iostream>
#include <stack>
#include <string>
using namespace std;

//考虑情况有局限，无法通过
//class Solution {
//public:
//    bool isValid(string s) {
//        if (s.size()==0)
//            return true;
//        if (s.size()%2!=0)
//            return false;
//        int x=0,y=0,z=0,w=0,p=0;
//        for (int i=0;i<s.size();i++){
//            if (s[i]=='('||s[i]=='['||s[i]=='{')
//                w+=1;
//            if (s[i]==')'||s[i]==']'||s[i]=='}')
//                p+=1;
//        }
//        if (w!=p)
//            return false;
//        for (int i=0;i<s.length();i++){
//            if (s[i]==')'||s[i]==']'||s[i]=='}'){
//                x=i;
//                for (int j=0;j<x-2*y;j++){
//                    if ((s[x-1-j]=='(' &&s[x+j]!=')') || (s[x-1-j]=='[' &&s[x+j]!=']') || (s[x-1-j]=='{' &&s[x+j]!='}'))
//                        return false;
//                    z+=1;
//                }
//                y=z;
//            }
//        }
//        if (y==0)
//            return false;
//        return true;
//    }
//};

//int main(){
//    string s="[]";
//    int x=0;
//    for (int i=0;i<s.length();i++){
//        if (s[i]==')'||s[i]==']'||s[i]=='}'){
//            x=i;
//            break;
//        }
//    }
//    cout<<x<<endl;
//    return 0;
//}

//栈应用
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> t;
//        for (int i=0;i<s.size();i++){
//            if (s[i]=='('||s[i]=='['||s[i]=='{'){
//                t.push(s[i]);
//                continue;
//            }
//            if (s[i]==')'||s[i]==']'||s[i]=='}'){
//                if (t.empty()){
//                    return false;
//                } else if (s[i]==')'&& t.top()!='('){
//                    return false;
//                }
//                else if (s[i]==']'&& t.top()!='[') {
//                    return false;
//                }
//                else if (s[i]=='}'&& t.top()!='{'){
//                    return false;
//                }else{
//                    t.pop();
//                }
//            }
//        }
//        if (t.empty()){
//            return true;
//        }
//        return false;
//    }
//};






























