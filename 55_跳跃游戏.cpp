#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > res || res >= nums.size() - 1)
				break;
			res = max(res, i + nums[i]);
		}
		return res >= nums.size() - 1;
	}
};

class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
			if (dp[i] < 0)
				return false;
		}
		return true;
	}
};