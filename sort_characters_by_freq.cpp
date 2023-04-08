#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static compare(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        map<char, int> count1;
        
        for(auto c: s){
            count1[c]++;
        }
        
        vector<pair<char, int>> count;
        for(auto &c: count1){
            count.push_back(c);
        }
        
        sort(count.begin(), count.end(), compare);
        
        string result="";
        for(auto str: count){
            for(int i=0; i<str.second; i++){
                result += str.first;
            }
        }
        
        return result;
    }
};