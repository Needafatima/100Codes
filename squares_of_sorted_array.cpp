#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             nums[i]*=nums[i];
//         }
        
//         sort(nums.begin(),nums.end());
        
        vector<int> result(nums.size(), 0);
        
        for(int left=0, right=nums.size()-1, k=nums.size()-1; left<=right; k--){
            if(abs(nums[left]) > abs(nums[right])){
                result[k]=nums[left]*nums[left];
                left++;
            }else{
                result[k]=nums[right]*nums[right];
                right--;
            }
        }
        
        return result;
    }
};