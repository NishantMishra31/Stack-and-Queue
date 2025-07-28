#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> stk;
    
    for(int i = n - 1; i >= 0; i--){
        while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
        if(stk.empty()) nge[i] = -1;
        else nge[i] = stk.top();
        stk.push(arr[i]);
    }
    return nge;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> nge = nextGreaterElement(arr);
    for(int i = 0; i < n; i++) cout << nge[i] << " ";
    return 0;
}
