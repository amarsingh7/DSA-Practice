//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
        long long ans=1;
        long long res=0;
        vector<int> v={9, 1, 3, 5, 7};
        while(N)
        {
            res= v[N%5] * ans +res;
            if(N%5 ==0)
                N=N/5 -1;
            else
                N= N/5;
                
            ans= ans*10;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends