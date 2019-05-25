#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty())
			return {};
		sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {return a.start < a.end; });
		vector<Interval> res{ intervals[0] };
		for (int i = 1; i < intervals.size(); ++i) {
			if (res.back().end < intervals[i].start) {
				res.push_back(intervals[i]);
			}
			else {
				res.back().end = max(res.back().end, intervals[i].end);
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		int n = intervals.size();
		vector<Interval> res;
		vector<int> starts, ends;
		for (int i = 0; i < n; ++i) {
			starts.push_back(intervals[i].start);
			ends.push_back(intervals[i].end);
		}
		sort(starts.begin(), starts.end());
		sort(ends.begin(), ends.end());
		for (int i = 0, j = 0; i < n; ++i) {
			if (i == n - 1 || starts[i + 1] > ends[i]) {
				res.push_back(Interval(starts[j], ends[i]));
				j = i + 1;
			}
		}
		return res;
	}
};