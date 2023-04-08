#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT_MAX;
        int left=0, val_sum=0;
        
        for(int right=0; right<nums.size(); right++){
            val_sum+=nums[right];
            
            while(val_sum>=target){
                result=min(result,right-left+1);
                
                val_sum-=nums[left];
                left++;
            }
        }
        
        return result!=INT_MAX ? result :0;
    }
};