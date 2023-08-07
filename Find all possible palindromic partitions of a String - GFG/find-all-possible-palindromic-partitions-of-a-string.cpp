//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool palind(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++] !=s[end--])
                return false;
        }
        return true;
    }
    void dfs(vector<vector<string>> &ans, vector<string> &temp, string s, int start)
    {
        if(start== s.size())
            ans.push_back(temp);
        for(int i=start; i<=s.size(); i++)
        {
            if(palind(s, start, i))
            {
                temp.push_back(s.substr(start, i-start+1));
                dfs(ans, temp, s, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(ans, temp, S, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends