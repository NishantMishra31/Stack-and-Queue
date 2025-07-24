#include<bits/stdc++.h>
using namespace std;

class myQueue{
    stack <int> stk1, stk2;

    public:
    myQueue() {}

    void push(int x){
        stk1.push(x);
    }

    int pop(){
        int val;
        if (!stk2.empty()){
            val = stk2.top();
            stk2.pop();
        }
        else{
            while(stk1.size()){
                stk2.push(stk1.top());
                stk1.pop();
            }
            val = stk2.top();
            stk2.pop();
        }
        return val;
    }

    int peek(){
        int val;
        if(!stk2.empty()) val = stk2.top();
        else{
            while(stk1.size()){
                stk2.push(stk1.top());
                stk1.pop();
            }
            val = stk2.top();
        }
        return val;
    }

    bool empty(){
        return (stk1.empty() && stk2.empty());
    }
};

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call
    myQueue que;
    for(int i = 0; i < n; i++){
        que.push(arr[i]);
    }
    while (!que.empty()){
        cout << que.peek() << " ";
        que.pop();
    }
    cout << endl << (que.empty() ? "Not empty" : "Empty");
    return 0;
}