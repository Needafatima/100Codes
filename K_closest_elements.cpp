#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int low=0,high=arr.size()-k;
        
//         while(low<high){
//             int mid=low+((high-low)/2);
            
//             if(x-arr[mid] > arr[mid+k] - x){
//                 low=mid+1;
//             }else{
//                 high=mid;
//             }
//         }
        
//         vector<int> result(arr.begin()+low,arr.begin()+low+k);
        
        priority_queue<pair<int, int>> maxHeap;
        
        for(auto num: arr){
            maxHeap.push({abs(x-num), num});
            
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        
        vector<int> result;
        
        while(maxHeap.size()>0){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};