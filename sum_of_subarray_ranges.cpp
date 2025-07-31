#include<bits/stdc++.h>
using namespace std;

// this is the naive approach to solve the subarray ranges problem

long long subArrayRanges(vector <int> &arr){
    int n = arr.size();
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int largest = arr[i], smallest = arr[i];
        for(int j = i + 1; j < n; j++){
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += (largest - smallest);
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
    cout << subArrayRanges(arr);
    return 0;
}