#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
//         int memo[n+1];
//         memo[0]=0;
        
//         for(int i=1;i<=n;i++){
//             memo[i]=i;
//             for(int j=1;j*j<=i;j++){
//                 int square=j*j;
//                 memo[i]=min(memo[i],1+memo[i-square]);
//             }
//         }
//         return memo[n];
        
        int dp[n+1];
        dp[0]=0;
        
        for(int target=1; target<=n; target++){
            dp[target]=target;
            for(int sq=1; sq<=target; sq++){
                int square=sq*sq;
                
                if(target-square < 0) break;
                
                dp[target]=min(dp[target], 1+dp[target-square]);
            }
        }
        
        return dp[n];
    }
};