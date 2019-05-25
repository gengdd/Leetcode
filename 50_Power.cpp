#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		double half = myPow(x, n / 2);
		if (n % 2 == 0)return half * half;
		if (n > 0) return half * half*x;
		return half * half/x;
	}
};

class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		for (int i = n; i != 0; i /= 2) {
			if (i % 2 != 0) res *= x;
			x *= x;
		}
		return n < 0 ? 1 / res : res;
	}
};
