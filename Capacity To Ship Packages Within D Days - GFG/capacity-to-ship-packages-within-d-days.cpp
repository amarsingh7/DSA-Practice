//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int rsum(int weights[], int n)
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+= weights[i];
        }
        return sum;
    }
    bool feasible(int weights[], int c, int days, int n)
    {
        int dn=1, cl= 0;
        for(int i=0; i<n; i++)
        {
            cl+= weights[i];
            if(cl> c)
            {
                dn++;
                cl= weights[i];
            }
        }
          return dn<= days;
    }
    int leastWeightCapacity(int weights[], int n, int days) {
        // code here
        int left= *max_element(weights, weights+n);
        int right= rsum(weights, n);
        int ans=0;
        
        while(left< right)
        {
            int mid= (left+right)/2;
            if(feasible(weights, mid, days, n))
                right= mid;
            else
                left= mid+1;
                
        }
        return left;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends