//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int rs(vector<int> nums, int mid)
    {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+= ceil(1.0*nums[i]/mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int left= 1;
        int right= *max_element(nums.begin(), nums.end());
        int res=-1;
        while(left<= right)
        {
            int mid= (right+left)/2;
            int sum= rs(nums, mid);
            if(sum<= K)
            {
                res= mid;
                right= mid-1;
            }
            else
                left= mid+1;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends