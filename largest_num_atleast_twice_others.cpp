#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex=-1,max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
                maxIndex=i;
            }
        }
        for(auto num:nums){
            if(num!=max && num*2>max){
                return -1;
            }
        }
        return maxIndex;
    }
};