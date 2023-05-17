//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int firstoc(int arr[], int n, int x)
{
    int start=0;
    int end=n-1;
    int first=-1;
    while(start<=end)
    {
        int mid= start +(end-start)/2;
        if(arr[mid]==x)
        {
            first= mid;
            end=mid-1;
        }
        else if(arr[mid]<x)
            start= mid+1;
        else
            end= mid-1;
    }
    return first;
}
int lastoc(int arr[], int n, int x)
{
    int start=0;
    int end=n-1;
    int second=-1;
    while(start<=end)
    {
        int mid= start +(end-start)/2;
        if(arr[mid]==x)
        {
            second= mid;
            start= mid+1;
        }
        else if(arr[mid]<x)
            start= mid+1;
        else
            end= mid-1;
    }
    return second;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v(2);
    v[0]= firstoc(arr, n, x);
    v[1]= lastoc(arr, n, x);
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends