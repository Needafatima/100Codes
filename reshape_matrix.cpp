#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m= mat.size() , n= mat[0].size();
        int total = m * n;
        
        if(r==m && c==n){
            return mat;
        }
        
        if(r*c != total){
            return mat;
        }
        
        vector<vector<int>> result(r, vector<int>(c));
        
        for(int i=0; i<total; i++){
            result[i/c][i%c] = mat[i/n][i%n];
        }
        
        return result;
    }
};