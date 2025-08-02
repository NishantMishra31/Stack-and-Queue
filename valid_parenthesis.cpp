#include<bits/stdc++.h>
using namespace std;

// classic valid parenthesis problem
// problem - 
/* An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */

bool isValid(string s){
    int n = s.size();
    stack <char> stk;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
        else{
            if(stk.empty()) return false;
            char ch = stk.top();
            stk.pop();
            if ((s[i] == ')' && ch == '(') ||
                (s[i] == '}' && ch == '{') ||
                (s[i] == ']' && ch == '[')){
                continue;
            }
            else return false;
        }
    }
    return stk.empty();
}

int main(){
    string s;
    cin >> s;
    cout << isValid(s);
    return 0;
}