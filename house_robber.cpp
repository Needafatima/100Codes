#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robHouse(vector<int>& nums, vector<int>& memo, int n){
        if(n<0){
            return 0;
        }
        
        if(memo[n] != -1){
            return memo[n];
        }
        
        return memo[n] = max(nums[n] + robHouse(nums, memo, n-2), robHouse(nums, memo, n-1));
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return robHouse(nums, memo, nums.size()-1);
    }
};