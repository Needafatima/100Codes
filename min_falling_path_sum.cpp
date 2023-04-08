#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[101][101];
    
    int bfs(vector<vector<int>>& matrix, int i, int j){
        if(i<0 || i>=matrix.size()){
            return 0;
        }
        
        if(j<0 || j>=matrix[i].size()){
            return INT_MAX;
        }
        
        if(memo[i][j]!=0){
            return memo[i][j];
        }
        
        return memo[i][j]=min(
            min(
                bfs(matrix, i+1, j-1),
                bfs(matrix, i+1, j)
            ),
                bfs(matrix, i+1, j+1)
            )+matrix[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum=INT_MAX;
        
        for(int j=0; j<matrix[0].size(); j++){
            minSum=min(minSum, bfs(matrix, 0, j));
        }
        
        return minSum;
    }
};