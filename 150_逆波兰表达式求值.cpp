#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 1) return stoi(tokens[0]);
		stack<int> st;
		for (int i = 0; i < tokens.size(); ++i) {
			if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
				st.push(stoi(tokens[i]));
			}
			else {
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				if (tokens[i] == "+") st.push(num1 + num2);
				if (tokens[i] == "-")  st.push(num2 - num1);
				if (tokens[i] == "*") st.push(num2*num1);
				if (tokens[i] == "/") st.push(num2 / num1);
			}
		}
		return st.top();
	}
};