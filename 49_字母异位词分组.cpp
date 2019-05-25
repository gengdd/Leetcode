#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>>m;
		for (string str : strs) {
			string t = str;
			sort(t.begin(), t.end());
			m[t].push_back(str);
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>>m;
		for (string str : strs) {
			vector<int> cnt(26, 0);
			string t = "";
			for (char c : str)
				++cnt[c - 'a'];
			for (int d : cnt)
				t += to_string(d) + "/";
			m[t].push_back(str);
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}
};