#include<bits/stdc++.h>
using namespace std;

// implement a stack using queue
// uses a inverse approach

class myStack{
    queue <int> q;
    public:
    myStack() {}
    void push(int x){
        int s = q.size();
        q.push(x);
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int val = q.front();
        q.pop();
        return val;
    }

    int top(){
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call
    myStack stk;
    for (int i = 0; i < n; i++){
            stk.push(arr[i]);
        }
    while (!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl << (stk.empty() ? "Not empty" : "Empty");
    return 0;
}