//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int help(int N)
    {
        if(N==1 || N==7)
            return 1;
        if(N>=2 and N<=9 and N!=7)
            return 0;
        int ans=0;
        while(N>0)
        {
            int r= N%10;
            r= r*r;
            ans+= r;
            N= N/10;
        }
        return help(ans);
        
    }
    int nextHappy(int N){
        // code here
        
        for(int i=N+1; i<= int(1e5); i++)
        {
            if(help(i)==1)
                return i;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends