//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int firstbuy= INT_MIN, secbuy= INT_MIN;
    int firstsell= 0, secsell= 0;
    
    for(int i=0; i<price.size(); i++)
    {
        firstbuy= max(firstbuy, -price[i]);
        firstsell= max(firstsell, price[i]+ firstbuy);
        secbuy= max(secbuy, firstsell- price[i]);
        secsell= max(secsell, secbuy+ price[i]);
        
    }
    return secsell;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends