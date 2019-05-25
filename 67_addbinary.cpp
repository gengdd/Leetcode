#include <iostream>
#include <string>
using namespace std;

//错误
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        int y,sum1=0,sum2=0;
//        for (int i=0;i<a.length();i++){
//            sum1=sum1*2+int(a[i]);
//        }
//        for (int i=0;i<b.length();i++){
//            sum2=sum2*2+int(b[i]);
//        }
//        int sum=sum1+sum2;
//        string c="";
//        while (sum!=0){
//            y=sum%2;
//            sum=sum/2;
//            c=c+char(y);
//        }
//        return c;
//    }
//};


//二进制数相加，并且保存在string中，要注意的是如何将string和int之间互相转换，
// 并且每位相加时，会有进位的可能，会影响之后相加的结果。而且两个输入string的长度也可能会不同。
// 这时我们需要新建一个string，它的长度是两条输入string中的较大的那个，
// 并且把较短的那个输入string通过在开头加字符‘0’来补的较大的那个长度。
// 这时候我们逐个从两个string的末尾开始取出字符，然后转为数字，想加，
// 如果大于等于2，则标记进位标志carry，并且给新string加入一个字符‘0’。
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int na=a.size();
        int nb=b.size();
        int n=max(na,nb);
        bool carry= false;
        if (na>nb){
            for (int i=0;i<na-nb;++i)
                b.insert(b.begin(),'0');
        } else if (na<nb){
            for (int i=0;i<nb-na;++i)
                a.insert(a.begin(),'0');
        }
        for (int i=n-1;i>=0;--i){
            int tmp=0;
            if (carry)
                tmp=(a[i]-'0')+(b[i]-'0')+1;
            else
                tmp=(a[i]-'0')+(b[i]-'0');
            if (tmp==0){
                res.insert(res.begin(),'0');
                carry= false;
            } else if (tmp==1){
                res.insert(res.begin(),'1');
                carry= false;
            } else if (tmp==2){
                res.insert(res.begin(),'0');
                carry= true;
            } else if (tmp==3){
                res.insert(res.begin(),'1');
                carry= true;
            }
        }
        if (carry)
            res.insert(res.begin(),'1');
        return res;
    }
};






















