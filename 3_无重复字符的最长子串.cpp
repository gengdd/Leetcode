#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, left = -1, n = s.size();
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (m.count(s[i]) && m[s[i]] > left) {
				left = m[s[i]];
			}
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(128, -1);
		int res = 0, left = -1;
		for (int i = 0; i < s.size; ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, left = 0, i = 0, n = s.size();
		unordered_set<char> t;
		while (i < n) {
			if (!t.count(s[i])) {
				t.insert(s[i++]);
				res = max(res, (int)t.size());
			}
			else {
				t.erase(s[left++]);
			}
		}
		return res;
	}
};