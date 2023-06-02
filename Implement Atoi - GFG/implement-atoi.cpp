//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        vector<int> v={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int ans=0;
        int nans=0;
        string temp=str;
        sort(temp.rbegin(), temp.rend());
        int n= str.size();

        if(temp[0]>=97 ||(str[0]=='-' and (str[1]=='-' || str[1]=='+'))||str[2]=='-')
            return -1;
        if(str[0]=='-')
        {
            for(int i=1; i<n; i++)
            nans+= (str[i]-'0')*(pow(10, (n-i-1)));
        }
        else
        {
            for(int i=0; i<n; i++)
            ans+= (str[i]-'0')*(pow(10, (n-i-1)));
        }
        
        if(str[0]=='-')
            return nans*(-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends