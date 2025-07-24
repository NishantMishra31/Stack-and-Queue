#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    stack <int> stk;
    for(int i = 0; i < n; i++) stk.push(arr[i]);
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}