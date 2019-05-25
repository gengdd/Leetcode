#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//´íÎó
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		int n = s.size();
//		int x = 0;
//		if (n % (numRows + numRows - 2) <= numRows)
//			x = (numRows - 1)*n / (numRows + numRows - 2) + 1;
//		else {
//			x = (numRows - 1)*n / (numRows + numRows - 2) + 1 + (n % (numRows + numRows - 2) - numRows);
//		}
//		string t[numRows][x] = { 0 };
//		int y = 0;
//		for (int i = 0; i < x; ++i) {
//			if (i%(numRows-1) == 0) {
//				for (int j = 0; j < numRows; j++) {
//					t[j][i] = s[y++];
//				}
//			}
//			if (i % (numRows - 1) != 0) {
//				t[numRows - (i % (numRows - 1)) - 1][i] = s[y++];
//			}
//		}
//		string res;
//		for (int j = 0; j < numRows; ++j) {
//			for (int i = 0; i < x; ++i) {
//				if (t[j][i] != 0) {
//					res.push_back(t[j][i]);
//				}
//			}
//		}
//		return res;
//	}
//};


class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;
		string res = "";
		int size = 2 * numRows - 2;
		for (int i = 0; i < numRows; ++i) {
			for (int j = i; j < s.size(); j+=size) {
				res += s[j];
				int tmp = j + size - 2 * i;
				if (i != 0 && i != numRows - 1 && tmp < s.size())
					res += s[tmp];
			}
		}
		return res;
	}
};
