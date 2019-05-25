#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int n = s.size(), maxLen = 0, start = 0;
		for (int i = 0; i < n - 1; ++i) {
			searchPalindrome(s, i, i, start, maxLen);
			searchPalindrome(s, i, i + 1, start, maxLen);
		}
		return s.substr(start, maxLen);
	}
	void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		if (maxLen < right - left - 1) {
			start = left + 1;
			maxLen = right - left - 1;
		}
	}
};

//DP
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		int dp[s.size()][s.size()] = { 0 }, left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < i; j++) {
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
					right = i;
				}
			}
			dp[i][i] = 1;
		}
		return s.substr(left, right - left + 1);
	}
};

//mamacher
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += "#";
		}
		vector<int> p(t.size(), 0);
		int mx = 0, id = 0, resLen = 0, resCenter = 0;
		for (int i = 1; i < t.size(); ++i) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (t[i + p[i]] == t[i - p[i]])
				++p[i];
			if (mx < i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			if (resLen < p[i]) {
				resLen = p[i];
				resCenter = i;
			}
		}
		return s.substr((resCenter - resLen) / 2, resLen - 1);
	}
};