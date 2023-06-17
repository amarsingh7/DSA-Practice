//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void help(vector<int> &arr, vector<int> &temp, int index, vector<int> &ans) {
    if (index == arr.size()) {
        int res = accumulate(temp.begin(), temp.end(), 0);
        ans.push_back(res);
        return;
    }

    help(arr, temp, index + 1, ans);
    temp.push_back(arr[index]);
    help(arr, temp, index + 1, ans);
    temp.pop_back();
}

vector<int> subsetSums(vector<int> arr, int N) {
    vector<int> ans;
    vector<int> temp;
    help(arr, temp, 0, ans);
    return ans;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends