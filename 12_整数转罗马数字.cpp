#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		vector<char> roman{ 'M','D','C','L','X','V','I' };
		vector<int> value{ 1000,500,100,50,10,5,1 };
		for (int n = 0; n < 7; n += 2) {
			int x = num / value[n];
			if (x < 4) {
				for (int i = 1; i <= x; ++i)
					res += roman[n];
			}
			else if (x==4){
				res = res + roman[n] + roman[n - 1];
			}
			else if (x > 4 && x < 9) {
				res += roman[n - 1];
				for (int i = 6; i <= x; ++i)
					res += roman[n];
			}
			else if (x == 9) {
				res = res + roman[n] + roman[n - 2];
			}
			num %= value[n];
		}
		return res;	
	}
};

class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		vector<int> val{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> str{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		for (int i = 0; i < val.size(); ++i) {
			while (num >= val[i]) {
				num -= val[i];
				res += str[i];
			}
		}
		return res;
	}
};