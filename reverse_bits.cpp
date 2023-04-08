#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0) return 0;
        
        uint32_t result=0;
//         vector<int> binary;
        
//         int count=0;
//         while(n!=0){
//             binary.push_back(n%2);
//             n/=2;
//             count++;
//         }
//         count = 32-count;
        
//         for(int i=0;i<count;i++){
//                 binary.push_back(0);
//         }
        
//         for(int i=binary.size(); i>0; i--){
//             res = res + (pow(2,binary.size()-i) * (binary[i-1]));
//         }
        
        for(int i=0;i<32; i++){
            result <<= 1;
            if(n & 1 == 1) result++;
            n >>= 1;
        }
        
        return result;
    }
};