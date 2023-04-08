#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> freq;
        vector<string> result;
        
        if(s.length() < 10){
            return result;
        }
        
        for(int i=0; i<s.length()-9; i++){
            freq[s.substr(i,10)]++;
        }
        
        for(auto c: freq){
            if(c.second > 1){
                result.push_back(c.first);
            }
        }
        
        return result;
    }
};