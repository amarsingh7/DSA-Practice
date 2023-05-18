//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int start=0, end= n-1;
        while(start <end)
        {
            int mid= (start+end)/2;
            if(arr[start]< arr[end])
                return arr[start];
            if(arr[mid] >=arr[start])
                start= mid+1;
            else
                end= mid;
        }
        return arr[start];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends