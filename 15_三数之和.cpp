#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

//´íÎó
//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>> w;
//		vector<int> s;
//		unordered_map<int, int> t;
//		for (int i = 0; i < nums.size(); ++i) {
//			t[-nums[i]] = i;
//		}
//		for (int i = 0; i < nums.size(); ++i) {
//			for (int j = i + 1; j < nums.size(); ++j) {
//				if (t.count(nums[i] + nums[j])&&t.count(nums[i] + nums[j]) != i && t.count(nums[i] + nums[j]) != j) {
//					s.push_back(i);
//					s.push_back(j);
//					s.push_back(t.count(nums[i] + nums[j]));
//					w.push_back(s);
//				}
//			}
//		}
//		return w;
//	}
//};

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		for (int k = 0; k < nums.size(); ++k) {
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue;
			int target = 0 - nums[k];
			int i = k + 1, j = nums.size() - 1;
			while (i < j) {
				if (nums[i] + nums[j] == target) {
					res.push_back({ nums[k],nums[i],nums[j] });
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j - 1]) --j;
					++i;
					--j;
				} else if (nums[i] + nums[j] < target) ++i;
				else --j;
			}
		}
		return res;
	}
};



