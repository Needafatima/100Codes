#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea;
    
    void findArea(vector<vector<int>>& grid, int i, int j, int &count, vector<vector<int>>& visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || visited[i][j]){
            return;
        }
        
        visited[i][j] = 1;
        if(grid[i][j] == 1){
            count++;
            maxArea=max(maxArea,count);

            // bfs
            findArea(grid, i+1, j, count, visited); //down
            findArea(grid, i-1, j, count, visited); //up
            findArea(grid, i, j+1, count, visited); //right
            findArea(grid, i, j-1, count, visited); //left   
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxArea = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j] && grid[i][j]){
                    int count=0;
                    findArea(grid, i, j, count, visited);
                }
            }
        }
        
        return maxArea;
    }
};