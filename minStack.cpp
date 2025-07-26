#include<bits/stdc++.h>
using namespace std;

class MinStack{
    
    stack <pair<int, int>> stk;

    public:
    MinStack() {}

    void push(int val){
        if(stk.empty()) stk.push({val, val});
        else stk.push({val, min(stk.top().second, val)});
    }

    void pop(){
        stk.pop();
    }

    int top(){
        return stk.top().first;
    }

    int getMin(){
        return stk.top().second;
    }
};

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call for testing
    MinStack stk;
    for(int i = 0; i < n; i++) stk.push(arr[i]);
    cout << stk.getMin() << " ";
    stk.pop();
    stk.pop();
    cout << stk.getMin() << " ";
    return 0;
}