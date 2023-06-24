//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int fuck(string &str, string &x)
    {
        int count=0;
        int temp=0;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]==x[i])
                temp++;
        }
        if(temp==str.size())
            count++;
        return count;
    }
    int klengthpref(string arr[], int n, int k, string str){    
        // sort(str.begin(), str.end());
        string fck="";
        for(int i=0; i<k; i++)
        {
            fck.push_back(str[i]);
        }
        int res=0;
        for(int i=0; i<n; i++)
        {
            res+= fuck(fck, arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends