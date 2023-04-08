#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>board;
    vector<vector<string>> result;
    
    bool queen_not_under_attack(int n, int rowNo, int colNo){
        // Check for Q under same row
        for(int i=0;i<n;i++){
            if(board[rowNo][i]=='Q'){
                return false;
            }
        }
        
        // Check for Q under same column
        for(int i=0;i<n;i++){
            if(board[i][colNo]=='Q'){
                return false;
            }
        }
        
        // Check for Q under same diagonal(top left to bottom right)
        for(int i=0;i<n;i++){
            if(rowNo+i<n && colNo+i<n){
                if(board[rowNo+i][colNo+i]=='Q'){
                    return false;
                }
            }else{
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(rowNo-i>=0 && colNo-i>=0){
                if(board[rowNo-i][colNo-i]=='Q'){
                    return false;
                }
            }else{
                break;
            }
        }
        
        // Check for Q under same diagonal(top right to bottom left)
        for(int i=0;i<n;i++){
            if(rowNo+i<n && colNo-i>=0){
                if(board[rowNo+i][colNo-i]=='Q'){
                    return false;
                }
            }else{
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(rowNo-i>=0 && colNo+i<n){
                if(board[rowNo-i][colNo+i]=='Q'){
                    return false;
                }
            }else{
                break;
            }
        }
        
        return true;
    }
    
    void dfs(int n, int rowNo){
        if(rowNo==n){
            result.push_back(board);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(queen_not_under_attack(n,rowNo,col)){
                board[rowNo][col]='Q';
                dfs(n,rowNo+1);
                board[rowNo][col]='.';
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        string start="";
        
        for(int i=0;i<n;i++){
            start+=(".");
        }
        
        board=vector<string>(n,start);
        dfs(n,0);
        
        return result.size();
    }
};