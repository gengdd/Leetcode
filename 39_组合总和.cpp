#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//DFS
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		combinationSumDFS(candidates, target, 0, {}, res);
		return res;
	}
	void combinationSumDFS(vector<int>&candidates, int target, int start, vector<int>out, vector<vector<int>>&res) {
		if (target < 0)
			return;
		if (target == 0) {
			res.push_back(out);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], i, out, res);
			out.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i) {
			if (candidates[i] > target) break;
			if (candidates[i] == target) {
				res.push_back({ candidates[i] });
				break;
			}
			vector<int> vec = vector<int>(candidates.begin() + i, candidates.end());
			vector<vector<int>> tmp = combinationSum(vec, target - candidates[i]);
			for (auto a : tmp) {
				a.insert(a.begin(), candidates[i]);
				res.push_back(a);
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<vector<int>>> dp;
		sort(candidates.begin(), candidates.end());
		for (int i = 1; i <= target; ++i) {
			vector<vector<int>> cur;
			for (int j = 0; j < candidates.size(); ++j) {
				if (candidates[j] > i)  break;
				if (candidates[j] == i) {
					cur.push_back({ candidates[j] });
					break;
				}
				for (auto a : dp[i - candidates[j] - 1]) {
					if (candidates[j] > a[0])
						continue;
					a.insert(a.begin(), candidates[j]);
					cur.push_back(a);
				}
			}
			dp.push_back(cur);
		}
		return dp[target - 1];
	}
};