#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string output;
        int num=0;
        
        for(auto c:s){
            if(isdigit(c)){
                num=(num*10)+(c-'0');
            }else if(isalpha(c)){
                output.push_back(c);
            }else if(c == '['){
                chars.push(output);
                output="";
                nums.push(num);
                num=0;
            }else if(c == ']'){
                string temp=output;
                for(int i=0; i< nums.top()-1;i++){
                    output+=temp;
                }
                output=chars.top()+output;
                chars.pop();
                nums.pop();
            }
        }
        
        return output;
    }
};