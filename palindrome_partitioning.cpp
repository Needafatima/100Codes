#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(string &s, vector<vector<string>> &result, vector<string> &subset, int start){
        if(start>=s.length()){
            result.push_back(subset);
        }
        
        for(int end=start; end<s.length(); end++){
            if(isPalindrome(s, start, end)){
                subset.push_back(s.substr(start, end-start+1));
                solve(s, result, subset, end+1);
                subset.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subset;
        
        solve(s, result, subset, 0);
        
        return result;
    }
};