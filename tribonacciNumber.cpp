#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n<2){
            return n;
        }
        
        vector<int> memo(n+1, 0);
        
        memo[0]=0;
        memo[1]=memo[2]=1;
        
        
        for(int i=3; i<=n; i++){
            memo[i]=memo[i-1]+memo[i-2]+memo[i-3];
        }
        
        return memo[n];
    }
};