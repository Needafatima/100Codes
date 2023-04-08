#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int maxProd=INT_MIN;
        int maxLen=0;
         
        for(int i=0; i<n;){
            int start=i;
            while(start<n && nums[start]==0) start++; 
            
            int end=start;
            int count=0;
            int startNeg=-1, endNeg=-1;
            
            while(end<n && nums[end]!=0){
                if(nums[end]<0){
                    count++;
                    
                    if(startNeg==-1){
                        startNeg=end;
                    }
                    endNeg=end;
                }
                end++;
            }
            
            if(count%2==0){
                maxLen=max(maxLen, end-start);
            }else{
                if(startNeg!=-1){
                    maxLen=max(maxLen, end-startNeg-1);
                }
                if(endNeg!=-1){
                    maxLen=max(maxLen, endNeg-start);
                }
            }
            
            i=end+1;
        }
        
        return maxLen;
    }
};