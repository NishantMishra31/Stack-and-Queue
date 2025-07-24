#include<bits/stdc++.h>
using namespace std;

class myQueue{
    stack <int> stk1, stk2;

    public:
    myQueue() {}

    void push(int x){
        while(stk1.size()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(x);
        while(stk2.size()){
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    int pop(){
        int val = stk1.top();
        stk1.pop();
        return val;
    }

    int peek(){
        return stk1.top();
    }

    bool empty(){
        return stk1.empty();
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