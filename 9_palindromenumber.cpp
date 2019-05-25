#include <iostream>
#include <string>
using namespace std;


//整数求解
//class Solution {
//public:
//    bool isPalindrome(int x) {
//        if (x<0){
//            return false;
//        } else{
//            int rev=0;
//            int s=x;
//            int y;
//            while (s!=0){
//                y=s%10;
//                s=s/10;
//                if (rev> INT_MAX/10||(rev==INT_MAX/10 && y>7))
//                    return false;
//                rev=rev*10+y;
//            }
//            if (x==rev){
//                return true;
//            } else{
//                return false;
//            }
//        }
//    }
//};

//字符串求解
class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        for (int i=0;i<s.size()/2;i++){
            if (s[i]!=s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};


//int main(){
//    int x=1234;
//    string s;
//    s=to_string(x);
//    for (int i=0;i<s.size();i++){
//        cout<<s[i]<<endl;
//    }
//    return 0;
//}




