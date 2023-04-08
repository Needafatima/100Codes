#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int>data;
    
    MinStack() {
        
    }
    
    void push(int val) {
        data.push_back(val);
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        int min_val=INT_MAX;
        for(auto num:data){
            min_val=min(min_val,num);
        }
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */