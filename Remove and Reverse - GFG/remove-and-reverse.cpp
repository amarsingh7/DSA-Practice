//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        vector<int>mp(26,0);
        int n=0;
        int c=0;
        for(auto a:s)
        {
            if(mp[a-'a']>=1) c++;
            mp[a-'a']++;
            n++;
        }
        if(c==0) 
         return s;
        int i=0,j=n-1;
        bool left=true;
        bool right=false;
      
        while(i<j)
        {
            if(c==0) break;
            if(left)
            {
                if(mp[s[i]-'a']>1)
                {
                    mp[s[i]-'a']--;
                    s[i]='X';
                    c--;
                    right=true;
                    left=false;
                }
                i++;
            }
            else 
            {
                if(mp[s[j]-'a']>1)
                {
                    mp[s[j]-'a']--;
                    s[j]='X';
                    c--;
                    right=false;
                    left=true;
                }
                j--;
            }
        }
        string ans="";
        if(left)
        {   
            for( i=0;i<n;i++)
            {
                if(s[i]!='X') ans+=s[i];
            }
        }
        else
        {
            for(i=n-1;i>=0;i--)
            {
                 if(s[i]!='X') ans+=s[i];
            }
        }
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
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends