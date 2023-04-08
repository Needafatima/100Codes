#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
//         map<char, int> freq;
        
//         for(auto c:s){
//             freq[c]++;
//         }
        
//         vector<int> result;
//         map<char, bool> includes;
//         int prev=0;
        
//         for(int i=0; i<s.length(); i++){
//             if(freq[s[i]]>0){
//                 freq[s[i]]--;
//             }
            
//             if(freq[s[i]] == 0){
//                 bool flag=true;
//                 for(auto c: includes){
//                     if(c.second && freq[c.first] != 0){
//                         flag=false;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     int len = i-prev+1;
//                     prev=i+1;
//                     result.push_back(len);
//                     // result.push_back(i);
//                     for(auto c: includes){
//                         includes.erase(c.first);
//                     }
//                 }
//             }
            
//             includes[s[i]] = true;
//         }
        
//         return result;
        
        map<char, int> occurrence;
        
        for(int i=0; i<s.length(); i++){
            occurrence[s[i]] = i;
        }
        
        int start=0, last=0;
        vector<int> result;
        
        for(int i=0; i<s.length(); i++){
            last = max(last, occurrence[s[i]]);
            
            if(last==i){
                result.push_back(last-start+1);
                start=last+1;
            }
        }
        
        return result;
    }
};