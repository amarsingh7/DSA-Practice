//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void search(vector<int>& num, int next, vector<int>& temp, int n, vector<vector<int> >& result)
    {
        if(n == 0)
        {
            result.push_back(temp);
            return;
        }
        
        if(n<0 || next==num.size())
            return;
            
        search(num, next+1, temp, n, result);
        temp.push_back(num[next]);
        
        search(num, next, temp, n- num[next], result);
        temp.pop_back();
    }
    
    vector<vector<int> > combinationSum(vector<int> &nums, int target) 
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<int> temp;
        search(nums, 0, temp, target, result);
        sort(result.begin(), result.end());
        return result;    
    }
     
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends