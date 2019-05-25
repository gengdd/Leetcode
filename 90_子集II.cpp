#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty()) return {};
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		int size = 1, last = nums[0];
		for (int i = 0; i < nums.size(); ++i) {
			if (last != nums[i]) {
				last = nums[i];
				size = res.size();
			}
			int newSize = res.size();
			for (int j = newSize - size; j < newSize; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty()) return {};
		vector<vector<int>> res;
		vector<int> out;
		sort(nums.begin(), nums.end());
		getSubsets(nums, 0, out, res);
		return res;
	}
	void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res) {
		res.push_back(out);
		for (int i = pos; i < nums.size(); ++i) {
			out.push_back(nums[i]);
			getSubsets(nums, i + 1, out, res);
			out.pop_back();
			while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
		}
	}
};