#include<bits/stdc++.h>
class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<char> st;
    int n = num.size();
    
    if (n <= k)   
        return "0";
    
    if (k == 0)
        return num;
    
    st.push(num[0]);

    for (int i = 1; i < n; i++) {
        while (k > 0 && !st.empty() && num[i] < st.top()) {
            st.pop();
            k--;
        }
        st.push(num[i]);
        
        if (st.size() == 1 && st.top() == '0') 
            st.pop();
    }
  
    while (k > 0 && !st.empty()) {  // 1234 type num case
        st.pop();
        k--;
    }
  
    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
  
    if (ans.empty())
        return "0";
    
    return ans;

    }
};