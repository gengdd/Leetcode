#include <iostream>
#include <string>

using namespace std;


//去空格
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        int num=0;
        int j;
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i] != ' '){
                j=i;
                break;
            }
        }
        for (int i=j;i>=0;i--){
            if (s[i]!=' ')
                num+=1;
            else
                break;
        }
        return num;
    }
};

//









