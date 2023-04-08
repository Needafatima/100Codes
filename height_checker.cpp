#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        
        for(auto num:heights){
            expected.push_back(num);
        }
        
        sort(expected.begin(),expected.end());
        
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(expected[i]!=heights[i]){
                count++;
            }
        }
        
        return count;
    }
};