//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPalindrome(string &s)
    {
		int n = s.size();
		int i = 0, j = n - 1;
		while (i < j) {
			if (s[i++] != s[j--])
				return false;
		}
		return true;
    }
    void dfs(vector<vector<string>>& result, vector<string>& subset, string& s, int start) {
    if (start == s.size()) 
    {
        result.push_back(subset);
        return;
    }
     
    string t;
    for(int i= start; i<s.size(); i++)
    {
        t.push_back(s[i]);
        if(isPalindrome(t))
        {
            subset.push_back(t);
            dfs(result, subset, s, i+1);
            subset.pop_back();
        }
    }
       
}

vector<vector<string>> allPalindromicPerms(string s) {
    vector<vector<string>> result;
    vector<string> subset;
    
    dfs(result, subset, s, 0);
    
    return result;
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