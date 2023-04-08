#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[1001];
    
    int climbStairs(vector<int>& cost, int n){
        if(n<2){
            return cost[n];
            // return 0;
        }
        
        if(memo[n]!=-1){
            return memo[n];
        }
        
        return  memo[n]=cost[n] + min(
                    climbStairs(cost, n-1),
                    climbStairs(cost, n-2)
                    );
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(memo, -1, sizeof memo);
        
        // return min(climbStairs(cost, n-1), climbStairs(cost, n-2));
        
        for(int i=0;i<n;i++){
            if(i<2){
                memo[i]=cost[i];
            }else{
                memo[i]=cost[i]+min(memo[i-1], memo[i-2]);   
            }
        }
        
        return min(memo[n-2], memo[n-1]);
    }
};