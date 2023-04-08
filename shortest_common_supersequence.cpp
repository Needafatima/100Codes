#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void LCS(vector<vector<int>> &t, string X, string Y, int m, int n){
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        
        vector<vector<int>> t(m+1,vector<int>(n+1, 0));
        
        LCS(t, str1, str2, m, n);
        
        cout<<t[m][n]<<endl;
        
        string result;
        int i=m, j=n;
        
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                result.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(t[i-1][j] >= t[i][j-1]){
                    result.push_back(str1[i-1]);
                    i--;
                }else if(t[i][j-1] > t[i-1][j]){
                    result.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        
        while(i>0){
            result.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0){
            result.push_back(str2[j-1]);
            j--;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};