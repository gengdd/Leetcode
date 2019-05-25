#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return {};
		vector<string> res;
		string dict[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		letterCombinationsDFS(digits, dict, 0, "", res);
		return res;
	}
	void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
		if (level == digits.size()) {
			res.push_back(out);
			return;
		}
		string str = dict[digits[level] - '0'];
		for (int i = 0; i < str.size(); ++i) {
			letterCombinationsDFS(digits, dict, level + 1, out + string(1, str[i]), res);
		}
	}
};

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return {};
		vector<string> res{ "" };
		string dict[]= { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		for (int i = 0; i < digits.size(); i++) {
			vector<string> t;
			string str = dict[digits[i] - '0'];
			for (int j = 0; j < str.size(); ++j) {
				for (string s : res) t.push_back(s + str[j]);
			}
			res = t;
		}
	}
};