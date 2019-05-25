#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> v;
		int i = 0;
		while (i < path.size()) {
			while (path[i] == '/'&&i < path.size())
				++i;
			if (i == path.size()) break;
			int start = i;
			while (path[i] != '/'&&i < path.size())
				++i;
			int end = i - 1;
			string s = path.substr(start, end - start + 1);
			if (s == "..") {
				if (!v.empty()) v.pop_back();
			}
			else if (s != ".") {
				v.push_back(s);
			}
		}
		if (v.empty()) return "/";
		string res;
		for (int i = 0; i < v.size(); ++i) {
			res += '/' + v[i];
		}
		return res;
	}
};

class Solution {
public:
	string simplifyPath(string path) {
		string res, t;
		stringstream ss(path);
		vector<string> v;
		while (getline(ss, t, '/')) {
			if (t == "" || t == ".") continue;
			if (t == ".." && !v.empty()) v.pop_back();
			else if (t != "..") v.push_back(t);
		}
		for (string s : v) res += "/" + s;
		return res.empty() ? "/" : res;
	}
};