#include <iostream>
#include <vector>
using namespace std;


//依次查找，将第一个不等于val的放在nums[0],依次类推。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0)
            return 0;
        int j=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=val){
                nums[j++]=nums[i];
            }
        }
        return j+1;
    }
};




























