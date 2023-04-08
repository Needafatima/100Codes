#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getBinary1Count(int num){
        int count=0;
        
        while(num!=0){
            if(num%2==1){
                count++;
            }
            num/=2;
        }
        
        return count;
    }
    
    static bool compare(pair<int,int> a, pair<int,int> b){
        if(a.second!=b.second){
            return a.second < b.second;
        }
        
        return a.first < b.first;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> result;
        vector<pair<int,int>> decimals;
        
        for(auto num:arr){
            decimals.push_back({num,getBinary1Count(num)});
        }
        
        sort(decimals.begin(),decimals.end(),compare);
        
        for(auto num:decimals){
            result.push_back(num.first);
        }
        
        return result;
    }
};