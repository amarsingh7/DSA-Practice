class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n= arr.size();
        if(k>n)
            return *max_element(arr.begin(), arr.end());
        int ans=0;
        int cur= arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i]<cur)
                ans+= 1;
            else
            {
                if(ans>=k)
                    return cur;
                cur= arr[i];
                ans=1;
            }
        }
        return cur;
        
    }
};