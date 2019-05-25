#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> out;
		helper(n, k, 1, out, res);
		return res;
	}
	void helper(int n, int k, int level, vector<int> &out, vector<vector<int>> &res) {
		if (out.size() == k) {
			res.push_back(out);
			return;
		}
		for (int i = level; i <= n; ++i) {
			out.push_back(i);
			helper(n, k, i + 1, out, res);
			out.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || k < 0) return {};
		if (k == 0) return { {} };
		vector<vector<int>> res = combine(n - 1, k - 1);
		for (auto &a : res)
			a.push_back(n);
		for (auto &a : combine(n - 1, k))
			res.push_back(a);
		return res;
	}
};
