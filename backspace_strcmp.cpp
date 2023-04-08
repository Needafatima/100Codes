#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string getTrimmedString(string &str){
        vector<char> res;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '#'){
                if(!res.empty()){
                    res.pop_back();   
                }
            }else{
                res.push_back(str[i]);
            }
        }
        
        string result;
        for(auto s:res){
            result+=s;
        }
        
        return result;
    }
    
    bool backspaceCompare(string s, string t) {
        s=getTrimmedString(s);
        t=getTrimmedString(t);
        
        return s==t;
    }
};