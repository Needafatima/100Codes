#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
//         map<char, int> index;
//         map<char, bool> reoccurrence;
        
//         int i=0;
//         for(auto str:s){
//             if(index[str]>0){
//                 reoccurrence[str]=true;
//                 // index[str]=-1;
//             }else{
//                 index[str]=i+1;
//                 reoccurrence[str]=false;
//             }
//             i++;
//         }
        
//         for(auto str:s){
//             if(index[str]>0 && !reoccurrence[str]){
//                 return index[str]-1;
//             }
//         }
        
        unordered_map<char, int> occurrence;
        
        for(auto str:s){
            occurrence[str]++;
        }
        
        int index=0;
        for(auto str:s){
            if(occurrence[str]==1){
                return index;
            }
            index++;
        }
        
        return -1;
    }
};