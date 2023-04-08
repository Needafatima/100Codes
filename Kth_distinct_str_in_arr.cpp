#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> frequency;
        
        for(auto str: arr){
            frequency[str]++;
        }
        
        int count=0;
        for(auto str: arr){
            if(frequency[str] == 1){
                count++;
                if(count == k){
                    return str;
                }
            }
        }
        
        return "";
    }
};