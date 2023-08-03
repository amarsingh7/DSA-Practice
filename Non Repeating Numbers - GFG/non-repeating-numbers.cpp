//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorfs=0, mask=1, first=0, second=0;
        vector<int> ans;
        
        for(auto x:nums)
            xorfs ^= x;
        
        while(!(xorfs & mask))
            mask <<=1;
        
        for(auto x:nums)
        {
            if(x & mask)
                first ^= x;
        }
        second= xorfs ^ first;
        
        return first<second ? vector<int>{first, second} : vector<int>{second, first};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends