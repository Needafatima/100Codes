#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> paren;
        string result;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                paren.push(s[i]);
            }else if(s[i] == ')'){
                if(paren.empty()){
                    s = s.substr(0,i) + s.substr(i+1);
                    i--;    
                }else{
                    paren.pop();
                }
            }
        }
        
        if(!paren.empty()){
            for(int i=s.length()-1; i>=0 && !paren.empty(); i--){
                if(s[i] == '('){
                    s = s.substr(0,i) + s.substr(i+1);
                    paren.pop();
                    i++;
                }
            }
        }
        
        return s;
    }
};