#include <iostream>
#include <stack>
#include <vector>

using namespace std;


//利用两个标准栈实现功能
class MinStack {
public:
    MinStack(){
    }
    void push(int x){
        s1.push(x);
        if (s2.empty()||x<=s2.top())
            s2.push(x);
    }
    void pop(){
        if (s1.top()==s2.top())
            s2.pop();
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    int getMin(){
        return s2.top();
    }

private:
    stack<int> s1,s2;
};
