//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string solve(string s1, string s2)
    {
        int n= s1.size();
        string ans="";
        for(int i=0; i<n; i++)
        {
            if(s1[0] !=s2[0])
                return "-1";
            if(s1[i]==s2[i])
                ans+= s1[i];
        }
        return ans;
    }
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        sort(arr, arr+n);
        if(n==1)
        return arr[0];
        string ans="";
        ans+= solve(arr[0], arr[n-1]);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends