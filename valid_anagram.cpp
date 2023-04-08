#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        map<char, int> frequency;
        
//         for(auto c:s){
//             frequency[c]++;
//         }
        
//         for(auto c:t){
//             if(--frequency[c] < 0){
//                 return false;
//             }
//         }
        
//         for(auto c:s){
//             if(frequency[c] != 0){
//                 return false;
//             }
//         }
        
        int n=s.length();
        for(int i=0; i<n; i++){
            frequency[s[i]]++;
            frequency[t[i]]--;
        }
        
        for(auto freq: frequency){
            if(freq.second){
                return false;
            }
        }
        
        return true;
    }
};