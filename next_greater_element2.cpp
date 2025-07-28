#include<bits/stdc++.h>
using namespace std;

vector <int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> nge;
    stack<int> stk;

    for (int i = arr2.size() - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= arr2[i]) stk.pop();
        nge[arr2[i]] = stk.empty() ? -1 : stk.top();
        stk.push(arr2[i]);
    }

    vector<int> res;
    for (int num : arr1) {
        res.push_back(nge[num]);
    }
    return res;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    vector<int> result = nextGreaterElement(arr1, arr2);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}