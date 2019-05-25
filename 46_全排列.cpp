#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> out, visited(nums.size(), 0);
		permuteDFS(nums, 0, visited, out, res);
		return res;
	}
	void permuteDFS(vector<int>&nums, int level, vector<int>&visited, vector<int>&out, vector<vector<int>>&res) {
		if (level == nums.size()) {
			res.push_back(out);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == 1)
				continue;
			visited[i] = 1;
			out.push_back(nums[i]);
			permuteDFS(nums, level + 1, visited, out, res);
			out.pop_back();
			visited[i] = 0;
		}
	}
};

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>(1, vector<int>());
		vector<vector<int>> res;
		int first = nums[0];
		nums.erase(nums.begin());
		vector<vector<int>> words = permute(nums);
		for (auto &a : words) {
			for (int i = 0; i <= a.size(); ++i) {
				a.insert(a.begin() + i, first);
				res.push_back(a);
				a.erase(a.begin + i);
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res{ {} };
		for (int a : nums) {
			for (int k = res.size(); k > 0; --k) {
				vector<int> t = res.front();
				res.erase(res.begin());
				for (int i = 0; i <= t.size(); ++i) {
					vector<int> one = t;
					one.insert(one.begin() + i, a);
					res.push_back(one);
				}
			}
		}
		return res;
	}
};
