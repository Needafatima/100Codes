#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int reqSum=(n*(n+1))/2;
        
        int sum=0;
        
        for(auto num: nums){
            sum+=num;
        }
        
        return reqSum-sum;
    }
};