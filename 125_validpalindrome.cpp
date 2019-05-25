#include <iostream>
#include <string>

using namespace std;

//class Solution {
//public:
//bool isPalindrome(string s) {
//    string t;
//    for (int i = 0; i < s.size(); i++) {
//        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
//            t.push_back(s[i]);
//        }
//    }
//    for (int i = 0; i < t.size(); i++) {
//        if (t[i] >= 'A' && t[i] <= 'Z') {
//            t[i] = t[i] + 32;
//        }
//    }
//    cout<<t<<endl;
//    for (int i = 0; i < t.size() / 2; i++) {
//        if (t[i] != t[t.size() - 1 - i])
//            return false;
//    }
//    return true;
//}
//};

//class Solution {
//public:
//    bool isPalindrome(string s) {
//        int left=0,right=s.size()-1;
//        while (left<right){
//            if (!isAlphaNum(s[left]))
//                ++left;
//            else if (!isAlphaNum(s[right]))
//                --right;
//            else if ((s[left]+32-'a')%32!=(s[right]+32-'a')%32)
//                return false;
//            else{
//                ++left;
//                --right;
//            }
//        }
//        return true;
//    }
//    bool isAlphaNum(char &ch){
//        if (ch>='a'&& ch<='z')
//            return true;
//        if (ch>='A'&& ch<='Z')
//            return true;
//        if (ch>='0'&& ch<='9')
//            return true;
//        return false;
//    }
//};

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if ((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left; --right;
            }
        }
        return true;
    }
};



















