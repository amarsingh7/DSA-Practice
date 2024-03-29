// #define ll long long;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set <vector<int>> s;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int start = j+1;
                int end = n-1;
                while (start < end)
                {
                    long long sum;
                    sum = ((long long)arr[i]+arr[j])+(long long)(arr[start]+arr[end]);
                    if (sum == k)
                    {
                        s.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }
                    else if (sum > k)
                    {
                        end--;
                    }
                    else 
                    {
                        start++;
                    }
                }
            }
        }
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};