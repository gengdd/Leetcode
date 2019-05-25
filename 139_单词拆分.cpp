#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), -1);
		return check(s, wordSet, 0, memo);
	}
	bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
		if (start >= s.size()) return true;
		if (memo[start] != -1) return memo[start];
		for (int i = start + 1; i <= s.size(); ++i) {
			if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
				return memo[start] = 1;
			}
		}
		return memo[start] = 0;
	}
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1);
		dp[0] = true;
		for (int i = 0; i < dp.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[j] && wordSet.count(s.substr(j, i - j))) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};


