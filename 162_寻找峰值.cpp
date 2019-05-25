#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		nums.insert(nums.begin(), INT_MIN);
		nums.push_back(INT_MIN);
		for (int i = 1; i < (int)nums.size() - 1; ++i) {
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
		}
		return -1;
	}
};
