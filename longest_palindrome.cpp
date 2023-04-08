#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> freq;
        
        for(auto c:s){
            freq[c]++;
        }
        
        int result=0;
        int oddLen=0;
        
        for(auto c:freq){
            result += ((c.second/2) * 2);
            if(c.second % 2 == 1){
                oddLen++;
            }
        }
       
        if(oddLen>0){
            result++;
        }
        
        return result;
        
//         vector<int> count(128);
        
//         for(auto c:s){
//             count[c]++;
//         }
        
//         int result=0;
        
//         for(auto c:count){
//             result += ((c/2)*2);
            
//             if(result % 2 == 0 && c % 2 == 1){
//                 //now result will be odd and will never be even again!
//                 result += 1;    
//             }
//         }
        
//         return result;
    }
};