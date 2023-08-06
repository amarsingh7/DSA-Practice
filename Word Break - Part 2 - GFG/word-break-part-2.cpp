//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans; 
        // Vector to store the final word break combinations
        
        unordered_set<string> st; 
        // Store words into a set for faster lookup
        for (auto x : dict)
            st.insert(x);
        
        string curr = ""; 
        // String to store the current word break combination
        solve(0, s, st, curr, ans); 
        // helper to find all possible word break combinations
        
        return ans; 
        // Return the result
    }
    
    void solve(int index, string s, unordered_set<string>& st, string curr, vector<string>& ans) {
        if (index == s.size()) { 
            // Base case: If we have reached the end of string
            curr.pop_back(); 
            // Remove the trailing space
            ans.push_back(curr); 
            // Add the current word break to the result 
            return;
        }
        
        string str = ""; 
        // String to store the current substring
        for (int i = index; i < s.size(); i++) {
            str.push_back(s[i]); 
            // Add the current char to the current substring
            if (st.count(str)) { 
                // Check if the current substring present
                solve(i + 1, s, st, curr + str + " ", ans); 
                //call to explore further with the current substring
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends