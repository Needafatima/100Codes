#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                // int temp=nums[i];
                // nums[i]=nums[pIndex];
                // nums[pIndex]=temp;
                swap(nums[i], nums[pIndex]);
                pIndex++;
            }
        }
        return nums;
    }
};