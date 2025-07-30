#include<bits/stdc++.h>
using namespace std;


int sumSubarrayMins(vector <int> &arr){
    int n = arr.size();
    int sum = 0, mod = 1e9 + 7;
    for(int i = 0; i < n; i++){
        int mini = arr[i];
        for(int j = i; j < n; j++){
            mini = min(mini, arr[j]);
            sum += mini % mod;
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call
    cout << sumSubarrayMins(arr);
    return 0;
}