#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static compare(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> count;
        
        for(auto num: nums){
            count[num]++;
        }
        
        vector<pair<int,int>> arr;
        for(auto num:count){
            arr.push_back({num.first, num.second});
        }
        
        sort(arr.begin(), arr.end(), compare);
        
        for(auto num:arr){
            result.push_back(num.first);
            if(result.size()==k){
                break;
            }
        }
        
        return result;
    }
};