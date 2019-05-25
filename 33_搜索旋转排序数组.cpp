#include<iostream>
#include<vector>
using namespace std;

//³¬Ê±
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (target < nums[0]) {
			for (int i = nums.size() - 1; i >= 0; i--) {
				if (nums[i] == target)
					return i;
				if (nums[i] > nums[0]) {
					return -1;
				}
			}
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == target)
					return i;
				if (nums[i] < nums[nums.size()-1])
					return -1;
			}
		}
		return -1;
	}
};

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < nums[right]) {
				if (nums[mid] < target&&nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			else {
				if (nums[left] <= target && nums[mid] > target)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		return -1;
	}
};