#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        return a.second < b.second;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        
//         vector<pair<pair<int, int>, int>> distance;
        
//         for(auto point:points){
//             int dist = (point[0]*point[0]) + (point[1]*point[1]);
//             distance.push_back({{point[0], point[1]}, dist});
//         }
        
//         sort(distance.begin(), distance.end(), compare);
        
//         for(auto point: distance){
//             result.push_back({point.first.first, point.first.second});
//             // cout<<point.second<<endl;
//             if(result.size() == k){
//                 break;
//             }
//         }
        
        priority_queue<pair<int, pair<int, int>>> distances;
        
        for(auto point:points){
            int dist = (point[0]*point[0]) + (point[1]*point[1]);
            distances.push({dist, {point[0], point[1]}});
            
            if(distances.size() > k){
                distances.pop();
            }
        }
        
        
        while(distances.size()>0){
            auto point = distances.top();
            distances.pop();
            result.push_back({point.second.first, point.second.second});
            // cout<<point.second<<endl;
        }
        
        return result;
    }
};