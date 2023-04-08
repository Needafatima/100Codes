#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[0][0] || grid[m-1][n-1]){
            return -1;
        }
        
        int count=0;
        queue<pair<int,int>> Q;
        Q.push({0,0});
        
        while(!Q.empty()){
            count++;
            
            int len=Q.size();
            
            for(int k=0; k<len; k++){
                auto C = Q.front(); Q.pop();
                int i = C.first, j=C.second;
                
                if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 1){
            continue;
        }
                if(i == m-1 && j == n-1){
                    return count;
                }
                
                grid[i][j] = 1;
                
                Q.push({i, j-1}); //left
                Q.push({i, j+1}); //right
                Q.push({i-1, j}); //up
                Q.push({i+1, j}); //down
                Q.push({i-1, j-1}); //top-left
                Q.push({i-1, j+1}); //top-right
                Q.push({i+1, j+1}); //bottom-right
                Q.push({i+1, j-1}); //bottom-left
            }
        }
        
        return -1;
    }
};