#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) return n;
		int pre = 0, cur = 1, count = 1;
		while (cur < n) {
			if (nums[pre] == nums[cur] && count == 0) ++cur;
			else {
				if (nums[pre] == nums[cur]) --count;
				else count = 1;
				nums[++pre] = nums[cur++];
			}
		}
		return pre + 1;
	}
};