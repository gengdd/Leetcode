#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		int m = matrix.size(), n = matrix[0].size();
//		int resm = 0;
//		for (int i = 0; i < m; ++i) {
//			if (i = 0 && matrix[i][0] > target)
//				return false;
//			if (i = m - 1 && matrix[i][0] < target)
//				return false;
//			if (i < m - 1 && matrix[i][0]<target && matrix[i + 1][0]>target) {
//				resm = i;
//				break;
//			}
//		}
//		int left = 0, right = n - 1;
//		while (left <= right) {
//			int mid = left + (right - left) / 2;
//			if (matrix[resm][mid] == target)
//				return true;
//			if (matrix[resm][mid] < target) {
//				left = mid + 1;
//			}
//			if (matrix[resm][mid] > target) {
//				right = mid - 1;
//			}
//		}
//		return false;
//	}
//};

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		if (target<matrix[0][0] || target>matrix.back().back()) return false;
		int left = 0, right = matrix.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (matrix[mid][0] == target) return true;
			else if (matrix[mid][0] < target) left = mid + 1;
			else right = mid - 1;
		}
		int tmp = right;
		left = 0;
		right = matrix[tmp].size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (matrix[tmp][mid] == target) return true;
			else if (matrix[tmp][mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
};