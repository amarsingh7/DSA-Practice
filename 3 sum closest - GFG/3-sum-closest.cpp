//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int target)
    {
        // code here
        int res= A[0]+A[1]+ A[N-1];
        sort(A, A+N);
        
        for(int i=0; i<N; i++)
        {
            int p1= i+1;
            int p2= N-1;
            
            while(p1<p2)
            {
                int csum= A[i]+A[p1]+ A[p2];
                if(csum>target)
                    p2 -=1;
                else
                    p1 += 1;
                if(abs(csum-target) <abs(res-target))
                    res= csum;
            }
            
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends