#include<bits/stdc++.h>
using namespace std;

// this a classic leetcode hard problem
// this approach takes TC O(3n) and SC O(2n)
// this extra space can be optimized using monotonic stack application

vector <int> prefixMax(vector<int> &height){
    int n =  height.size();
    vector <int> prefix(n);
    prefix[0] = height[0];
    for(int i = 1; i < n; i++){
        prefix[i] = max(prefix[i - 1], height[i]);
    }
    return prefix;
}

vector <int> suffixMax(vector<int> &height){
    int n =  height.size();
    vector <int> suffix(n);
    suffix[n-1] = height[n-1];
    for(int i = n - 2; i >= 0; i--){
        suffix[i] = max(suffix[i + 1], height[i]);
    }
    return suffix;
}

int trap(vector <int> &height){
    int n =  height.size();
    int total = 0;
    vector <int> prefix = prefixMax(height);
    vector <int> suffix = suffixMax(height);
    for(int i = 0; i < n; i++){
        int leftMax = prefix[i], rightMax = suffix[i];
        if(height[i] < leftMax && height[i] < rightMax){
            total += min(leftMax, rightMax) - height[i];
        }
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    vector <int> height(n);
    for(int i = 0; i < n; i++) cin >> height[i];
    // call
    cout << trap(height) << endl;
    return 0;
}
