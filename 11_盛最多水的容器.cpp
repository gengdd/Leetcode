#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//暴力算法超时
//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int max = 0;
//		for (int i = 0; i < height.size(); ++i) {
//			for (int j = i; j < height.size(); ++j) {
//				int area = min(height[i], height[j])*(j - i);
//				if (max < area)
//					max = area;
//			}
//		}
//		return max;
//	}
//};

//情况考虑少
//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int maxv = 0;
//		for (int i = 0; i < height.size(); ++i) {
//			if (height[i] > maxv) {
//				maxv = height[i];
//			}
//		}
//		vector<int> max_loc;
//		for (int i = 0; i < height.size(); ++i) {
//			if (height[i] == maxv) {
//				max_loc.push_back(i);
//			}
//		}
//		int marea = 0;
//		for (int j = 0; j < max_loc.size(); ++j) {
//			int loc = max_loc[j];
//			for (int i = 0; i < height.size(); ++i) {
//				int area = height[i]*abs(loc - i);
//				if (marea < area)
//					marea = area;
//			}
//		}
//		return marea;
//	}
//};

//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int dp[height.size()];
//		dp[0] = 0;
//		dp[1] = min(height[0], height[1]);
//		for (int i = 2; i < height.size(); ++i) {
//			int marea = 0;
//			for (int j = 0; j < i; ++j) {
//				int area = min(height[i], height[j])*(i - j);
//				if (marea < area)
//					marea = area;
//			}
//			dp[i] = max(dp[i - 1], marea);
//		}
//		return dp[height.size()];
//	}
//};

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0, i = 0, j = height.size() - 1;
		while (i < j) {
			res = max(res, min(height[i], height[j])*(j - i));
			height[i] < height[j] ? ++i : --j;
		}
		return res;
	}
};

