#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//nums[mid]可能等于nums[right]
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return false;
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) return true;
			else if (nums[mid] < nums[right]) {
				if (nums[mid] < target && nums[right] >= target) left = mid + 1;
				else right = mid - 1;
			}
			else if (nums[mid] > nums[right]) {
				if (nums[left] <= target && nums[mid] > target) right = mid - 1;
				else left = mid + 1;
			}
			else --right;
		}
		return false;
	}
};




