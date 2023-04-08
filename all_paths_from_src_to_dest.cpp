#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> &path, int node){  
        path.push_back(node);
      
        if(node == graph.size()-1){
            result.push_back(path);
        }else{
            for(auto i: graph[node]){
                dfs(graph, result, path, i);
            }    
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        
        if(graph.empty()){
            return result;
        }
        
        vector<int> path;
        
        dfs(graph, result, path, 0);
        
        return result;
    }
};