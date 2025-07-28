#include<bits/stdc++.h>
using namespace std;

vector <int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nge;
    stack<int> stk;

    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= nums2[i]) stk.pop();
        nge[nums2[i]] = stk.empty() ? -1 : stk.top();
        stk.push(nums2[i]);
    }

    vector<int> res;
    for (int num : nums1) {
        res.push_back(nge[num]);
    }
    return res;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for (int i = 0; i < n1; i++) cin >> nums1[i];
    for (int i = 0; i < n2; i++) cin >> nums2[i];
    vector<int> result = nextGreaterElement(nums1, nums2);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}