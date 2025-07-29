#include <bits/stdc++.h>
using namespace std;

// this is different than earlier NGE problem
// it solves for NGE in circular array

vector<int> nextGreaterElement(vector<int>& arr){
    int n = arr.size();
    vector <int> nge(n, -1);
    stack <int> stk;
    for(int i = 2*n - 1; i >= 0; i--){
        while(!stk.empty() && stk.top() <= arr[i % n]) stk.pop();
        if(i < n){
            nge[i] = stk.empty() ? -1 : stk.top();
        }
        stk.push(arr[i % n]);
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
