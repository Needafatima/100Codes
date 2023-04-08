#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        if(p.length()>s.length()){
            return {};
        }
        
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        
        for(int i=0; i<p.length(); i++){
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }
        
        int low=0, high=p.length()-1;
        
        while(high<s.length()){
            if(freqS == freqP){
                result.push_back(low);
            }
            
            high++;
            if(high != s.length()){
                freqS[s[high] - 'a']++;
            }
            
            freqS[s[low] - 'a']--;
            low++;
        }
        
        return result;
    }
};