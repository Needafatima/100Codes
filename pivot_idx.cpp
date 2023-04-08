#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOf(vector<int>& nums,int start,int end){
        int sum=0;
        for(int i=start;i<end;i++){
            sum+=nums[i];
        }
        return sum;
    }
    
    int pivotIndex(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     if(sumOf(nums,0,i)==sumOf(nums,i+1,nums.size())){
        //         return i;
        //     }
        // }
        
        int sum=0, leftSum=0;
        
        for(auto num: nums) sum+=num;
        
        for(int i=0; i<nums.size(); i++){
            if(leftSum == sum-leftSum-nums[i]) return i;
            
            leftSum+=nums[i];
        }
        
        return -1;
    }
};