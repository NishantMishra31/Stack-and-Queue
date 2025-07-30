#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    vector<int> st;
    int n = asteroids.size();
    for(int i = 0; i < n; i++){
        if(asteroids[i] > 0) st.push_back(asteroids[i]);
        else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back() == -asteroids[i]){
                st.pop_back();
                continue;
            }
            else if(st.empty() || st.back() < 0) st.push_back(asteroids[i]);
        }
    }
    return st;
}

int main(){
    int n;
    cin >> n;
    vector <int> asteroids(n);
    for(int i = 0; i < n; i++) cin >> asteroids[i];
    // call
    vector <int> ans = asteroidCollision(asteroids);
    for(auto ind : ans) cout << ind << " ";
    return 0;
}