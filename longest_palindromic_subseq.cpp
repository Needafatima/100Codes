#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LCS(string X, string Y){
        int n=X.length();
        
        int t[n+1][n+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }else if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }    
        }
            
        return t[n][n];
    }
    
    int longestPalindromeSubseq(string X) {
        string Y = X;
        reverse(X.begin(), X.end());
        
        return LCS(X,Y);
    }
};