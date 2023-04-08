#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int k=1;
    int n=0;
    vector<int> arr;
    
    Solution(vector<int>& nums) {
        n=nums.size();
        arr.swap(nums);
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> result(arr);
        
        for(int i=0; i<n; i++){
            int pos = rand() % (n-i);
            swap(result[pos+i], result[i]);
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */