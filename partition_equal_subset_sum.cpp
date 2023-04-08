#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num: nums){
            sum+=num;
        }
        
        if(sum%2!=0){
            return false;
        }
        
        int n=nums.size();
        sum/=2;
        int t[n+1][sum+1];
        
        for(int i=0; i<=sum; i++){
            t[0][i]=0;
        }
        for(int i=0; i<=n; i++){
            t[i][0]=1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
    }
};