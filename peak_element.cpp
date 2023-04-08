#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//         for(int i=1;i<nums.size();i++){
//             if(nums[i-1]>nums[i]){
//                 return i-1;
//             }
//         }
        
//         return nums.size()-1;
        
        int low=0,high=nums.size()-1;
        
        while(low<high){
            int mid=low+((high-low)/2);
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        
        return low;
    }
};