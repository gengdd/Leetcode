#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int m = nums.size() - 1;
//		for (int i = 1; i < m; ++i) {
//			for (int j = i-1; j >= 0; ++j) {
//				if (nums[i] < nums[j])
//					swap(nums[i], nums[j]);
//			}
//		}
//	}
//};


class Solution {
public:
	void sortColors(vector<int>& nums) {
		int res[3] = { 0 }, idx=0;
		for (int i = 0; i < nums.size(); ++i) {
			++res[nums[i]];
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < res[i]; ++j) {
				nums[idx++] = i;
			}
		}
	}
};

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0, blue = nums.size() - 1;
		for (int i = 0; i <= blue; ++i) {
			if (nums[i] == 0) {
				swap(nums[i], nums[red++]);
			}
			else if (nums[i] == 2) {
				swap(nums[i--], nums[blue--]);
			}
		}
	}
};
