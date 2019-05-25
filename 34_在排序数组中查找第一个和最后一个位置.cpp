#include<iostream>
#include<vector>
using namespace std;

//´íÎó
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int left = 0, right = nums.size() - 1;
//		vector<int> res;
//		while (left <= right) {
//			int mid = left + (right - left) / 2;
//			if ((nums[mid] == target && nums[mid - 1] < target)||(nums[mid] == target && nums[mid+1] > target)) {
//				res.push_back(mid);
//			}
//			else if (nums[mid] < target) {
//				left = mid + 1;
//				if (nums[left] == target)
//					res.push_back(left);
//			}
//			else
//			{
//				right = mid - 1;
//				if (nums[right] == target)
//					res.push_back(right);
//			}
//		}
//		return res;
//	}
//};

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int idx = search(nums, 0, nums.size() - 1, target);
		if (idx == -1) return { -1,-1 };
		int left = idx, right = idx;
		while (left > 0 && nums[left - 1] == nums[idx]) --left;
		while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
		return { left,right };
	}
	int search(vector<int>&nums, int left, int right, int target) {
		if (left > right)return -1;
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) return search(nums, mid + 1, right, target);
		else return search(nums, left, mid - 1, target);
	}
};

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		if (nums[right] != target) return res;
		res[0] = right;
		right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] <= target) left = mid + 1;
			else right = mid;
		}
		res[1] = left - 1;
		return res;
	}
};