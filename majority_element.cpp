#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         map<int,int> count;
//         int maxCount=INT_MIN;
//         int max=INT_MIN;
        
//         for(auto num:nums){
//             count[num]++;
//             // if(count[num] > maxCount){
//             //     maxCount = count[num];
//             //     max = num;
//             // }
//             if(count[num] > nums.size()/2){
//                 return num;
//             }
//         }
        
//         return max;
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()/2];
    }
};