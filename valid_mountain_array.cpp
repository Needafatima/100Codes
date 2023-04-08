#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        
        bool isIncreasing=true;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1] && isIncreasing && i>1){
                isIncreasing=false;
            }
            if(arr[i]==arr[i-1]){
                return false;
            }
            if(arr[i]>arr[i-1] && !isIncreasing){
                return false;
            }
            if(arr[i]<arr[i-1] && isIncreasing){
                return false;
            }
            
        }
        
        return !isIncreasing&&true;
    }
};