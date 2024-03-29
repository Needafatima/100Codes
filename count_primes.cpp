#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n){
        for(int i=2; i<=n/2; i++){
            if(n%i==0){
                return false;
            }
        }
        
        return true;
    }
    
    int countPrimes(int n) {
        int count=0;
        
        // for(int i=2; i<n; i++){
        //     if(isPrime(i)){
        //         count++;
        //     }
        // }
        
        vector<bool> primes(n, true);
        
        for(int i=2; i*i<n; i++){
            if(primes[i]){
                for(int j=i*i; j<n; j+=i){
                    primes[j]=false;
                }
            }
        }
        
        for(int i=2; i<n; i++){
            if(primes[i]){
                count++;
            }
        }
        
        return count;
    }
};