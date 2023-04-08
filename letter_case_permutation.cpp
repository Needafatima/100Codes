#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string> result;
        result.push(s);
        
        for(int i=s.length()-1; i>=0; i--){
            char c=s[i];
            if(isalpha(c)){
                int size = result.size();
                
                while(size-- > 0){
                    string str=result.front();
                    result.pop();
                    
                    string left = str.substr(0, i);
                    string right = str.substr(i+1, s.length());
                    
                    result.push(left + (char)tolower(c) + right);
                    result.push(left + (char)toupper(c) + right);
                }
            }
        }
    
        
        vector<string> res;
        int k=result.size();
        for(int i=0;i<k;i++){
            res.push_back(result.front());
            result.pop();
        }
        
        return res;
    }
};