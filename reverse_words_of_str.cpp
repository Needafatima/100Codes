#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string>result;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                string temp;
                int count=0;
                for(int j=i;j<s.length();j++,count++){
                    if(s[j]==' '){
                        break;
                    }else{
                        temp+=s[j];
                    }
                }
                result.push_back(temp);
                i+=count;
            }
        }
        
        reverse(result.begin(),result.end());
        string res;
        for(int i=0;i<result.size();i++){
            res+=result[i];
            if(i!=result.size()-1){
                res+=" ";
            }
        }
        return res;
    }
};