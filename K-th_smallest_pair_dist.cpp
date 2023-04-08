#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool okay(vector<int>& nums, int mid, int k){
        int n=nums.size();
        int total=0;
        
        for(int i=0,j=1;i<n;i++){
            while(j<n && nums[j]-nums[i]<=mid){
                j++;
            }
            j--;
            int x=j-i;
            total+=x;
        }
        
        return total>=k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int low=0, high=nums.back()-nums.front();
        
        while(low<high){
            int mid=low+((high-low)/2);
            
            if(okay(nums,mid,k)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        
        return low;
    }
};