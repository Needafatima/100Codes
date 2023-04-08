#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
//         if(!trust.size() && n==1){
//             return n;
//         }
        
//         map<int, bool> trusts;
//         map<int, bool> isTrusted;
//         map<int, int> noOfTrusts;
        
        vector<int> count(n+1, 0);
        
        for(auto T: trust){
            // trusts[T[0]] = true;
            // isTrusted[T[1]] = true;
            // noOfTrusts[T[1]]++;
            count[T[0]]--;
            count[T[1]]++;
        }
        
        for(int i=1; i<=n; i++){
            // if(!trusts[i] && isTrusted[i] && noOfTrusts[i]==n-1 ){
            //     return i;
            // }
            if(count[i] == n-1){
                return i;
            }
        }
            
        return -1;
    }
};