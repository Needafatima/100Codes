#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2){
            return true;
        }
        
        long low=1,high=num/2;
        
        while(low<=high){
            long mid=(low+high)/2;
            long sq=mid*mid;
            
            if(sq==num){
                return true;
            }
            
            if(sq>num){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};