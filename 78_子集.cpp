#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> res;
//		vector<int> out;
//		for (int i = 0; i < nums.size(); ++i) {
//			helper(res, out, i, 0, nums);
//		}
//		return res;
//	}
//	void helper(vector<vector<int>> &res, vector<int> &out, int i,int level,vector<int>&nums) {
//		if (out.size() == i) {
//			res.push_back(out);
//			return;
//		}
//		for (int j = level; j <= nums.size(); ++j) {
//			out.push_back(nums[j]);
//			helper(res, out, i, level + 1, nums);
//			out.pop_back();
//		}
//	}
//};


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int  size = res.size();
			for (int j = 0; j < size; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> out;
		sort(nums.begin(), nums.end());
		getSubsets(nums, 0, out, res);
		return res;
	}
	void getSubsets(vector<int> nums, int pos, vector<int> &out, vector<vector<int>> &res) {
		res.push_back(out);
		for (int i = pos; i < nums.size(); ++i) {
			out.push_back(nums[i]);
			getSubsets(nums, i + 1, out, res);
			out.pop_back();
		}
	}
};