#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int square(int n){
        int sum=0;
        while(n){
            int rem=n%10;
            sum += (rem*rem);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
//         int sum=n;
//         map<int, bool> seen;
        
//         while(true){
//             n=sum;
//             sum=0;
            
//             while(n){
//                 int rem=n%10;
//                 sum += (rem*rem);
//                 n/=10;
//             }
            
//             if(seen[sum]){
//                 return false;
//             }
            
//             cout<<sum<<endl;
            
//             if(sum==1){
//                 return true;
//             }
            
//             seen[sum] = true;
//         }
        
        
//         return false;
        int slow=n, fast=n;
        
        do{
            slow = square(slow);
            fast = square(fast);
            fast = square(fast);
        } while(slow != fast);
        
        if(slow==1) return true;
        return false;
    }
};