#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        map<int, pair<int,int>> dp; //key->index; value-> pair{length of LIS, count}
        int lenLIS=0, result=0;
        
        for(int i=nums.size()-1; i>=0; i--){
            int maxLen=1, maxCount=1;
            
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] < nums[j]){
                    auto [length, count] = dp[j];
                    if(length+1>maxLen){
                        maxLen = length+1;
                        maxCount=count;
                    }else if(length+1==maxLen){
                        maxCount+=count;
                    }
                }
            }
            
            if(maxLen > lenLIS){
                        lenLIS = maxLen;
                        result = maxCount;
            }else if(maxLen == lenLIS){
                result += maxCount;
            }
            
            dp[i] = {maxLen, maxCount};
        }
        
        return result;
    }
};