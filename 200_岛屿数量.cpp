#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size(), res = 0;
		vector<vector<bool>> visited(m, vector<bool>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i][j]) continue;
				helper(grid, visited, i, j);
				++res;
			}
		}
		return res;
	}
	void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y])
			return;
		visited[x][y] = true;
		helper(grid, visited, x - 1, y);
		helper(grid, visited, x + 1, y);
		helper(grid, visited, x, y - 1);
		helper(grid, visited, x, y + 1);
	}
};


class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size(), res = 0;
		vector<vector<bool>> visited(m, vector<bool>(n));
		vector<int> dirX{ -1,0,1,0 }, dirY{ 0,1,0,-1 };
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i][j]) continue;
				++res;
				queue<int> q{ {i*n + j} };
				while (!q.empty()) {
					int t = q.front();
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int x = t / n + dirX[k], y = t % n + dirY[k];
						if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y])
							continue;
						visited[x][y] = true;
						q.push(x*n + y);
					}
				}
			}
		}
		return res;
	}
};