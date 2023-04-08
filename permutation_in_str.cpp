#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Hash(26,0);
        vector<int> s2Hash(26,0);
        int s1Len=s1.length(), s2Len=s2.length();
        
        if(s1Len > s2Len){
            return false;
        }
        
        for(int i=0; i<s1Len; i++){
            s1Hash[s1[i] - 'a']++;
            s2Hash[s2[i] - 'a']++;
        }
        
        int left=0, right=s1Len-1;
        
        while(right<s2Len){
            if(s1Hash == s2Hash){
                return true;
            }
            
            right++;
            if(right!=s2Len){
                s2Hash[s2[right] - 'a']++;
            }
            s2Hash[s2[left] - 'a']--;
            left++;
        }
        
        return false;
    }
};