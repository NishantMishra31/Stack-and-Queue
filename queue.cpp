#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    queue <int> que;
    for(int i = 0; i < n; i++) que.push(arr[i]);
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    return 0;
}