//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        if(s.size() != t.size())
            return false;
        vector<int> mps(256, -1), mpt(256, -1);
        for(int i=0; i<s.size(); i++)
        {
            if(mps[s[i]] !=mpt[t[i]])
                return false;
            mps[s[i]]= mpt[t[i]]= i;
        }
        return true;
    
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends