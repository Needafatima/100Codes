#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-count;i++){
            if(nums[i]==0){
                // int temp=nums[i];
                // nums[i]=nums[nums.size()-count-1];
                // nums[nums.size()-count-1]=temp;
                for(int j=i+1;j<nums.size()-count;j++){
                    nums[j-1]=nums[j];
                }
                count++;
                nums[nums.size()-count]=0;
                if(nums[i]==0){
                    i--;
                }
            }
        }
    }
};