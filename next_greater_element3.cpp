#include <bits/stdc++.h>
using namespace std;

// this is different than earlier NGE problem
// it solves for NGE in circular array

vector<int> nextGreaterElement(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n, -1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < i + n; j++){
            int index = j % n;
            if(arr[index] > arr[i]){
                nge[i] = arr[index];
                break;
            }
        }
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
