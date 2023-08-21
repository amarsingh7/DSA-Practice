//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        bool dp[1001];
        memset(dp, false, sizeof(dp));
        
        int m= A.size();
        dp[m]= true;
        unordered_set<string> ust;
        for(auto x:B)
            ust.insert(x);
        for(int i= m-1; i>=0; i--)
        {
            for(int j=i; j<m; j++)
            {
                if(ust.count(A.substr(i, j-i+1)) and dp[j+1])
                    {
                        dp[i]= true; break;
                    } 
                
            }
        }
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends