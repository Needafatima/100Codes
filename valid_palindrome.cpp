#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
//         string p;
        
//         for(int k=0; k<s.length(); k++){
//             if(isalpha(s[k]) || isdigit(s[k]))
//                 p.push_back(tolower(s[k]));
//         }
        
//         int i=0, j=p.length()-1;
        
//         while(i<j){
//             char front=p[i], back=p[j];
//             if(front != back){
//                 return false;
//             }
            
//             i++;
//             j--;
//         }
        
        for(int i=0, j=s.length()-1; i<j; i++, j--){
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            
            if(tolower(s[i]) != tolower(s[j])) return false;
        }
        
        return true;
    }
};